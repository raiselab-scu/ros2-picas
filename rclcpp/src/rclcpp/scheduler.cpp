#include "rclcpp/scheduler.hpp"
#include "rclcpp/rclcpp.hpp"

#include <random>
#include <cmath>

using rclcpp::Scheduler;

Scheduler::Scheduler() {
    Scheduler::Init();
}

Scheduler::~Scheduler() {
}

void Scheduler::Init() {
    // 初始化Scheduler参数
    TaskBudgetTime = 100;
}

int Scheduler::Process() {
    int slack_time = CalculateSlackTime();

    int version = GetVersion(slack_time, 55); // 暂时假设任务需要55ms完成
    int priority = GetPriority(slack_time);

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Current task slack time: %d, version: %d, priority: %d", slack_time, version, priority);

    return priority;
}

int Scheduler::GetVersion(int slack_time, int expect_complete_time) {
    if (slack_time >= expect_complete_time) {
        return 1; // FP32
    } else if (slack_time >= expect_complete_time - 10) {
        return 2; // FP16
    } else if (slack_time >= expect_complete_time - 20) {
        return 3; // FP8
    } else {
        return 4; // INT8
    }
}

int Scheduler::GetPriority(int slack_time) {
    // 根据Slack Time计算任务优先级
    // 假设优先级范围为1-99，Slack Time越大，优先级越低
    int priority = 99 - (slack_time * 98 / 100);
    if (priority < 1) priority = 1;
    if (priority > 99) priority = 99;
    return priority;
}

int Scheduler::CalculateSlackTime() {
    int network_delay = GetNetworkDelay();
    int slack_time = TaskBudgetTime - network_delay;

    return slack_time;
}

int Scheduler::GetNetworkDelay() {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> delay_dist(30, 70); // 模拟网络延迟在30ms到70ms之间，则Slack Time范围在30ms - 70ms之间
    int delay = delay_dist(gen);
    return delay;
}