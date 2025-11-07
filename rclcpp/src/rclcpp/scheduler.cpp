#include "rclcpp/scheduler.hpp"
#include "rclcpp/rclcpp.hpp"

#include <random>
#include <cmath>
#include <vector>

using rclcpp::Scheduler;

Scheduler::Scheduler(): executor(nullptr) {
}

Scheduler::~Scheduler() {
}

int Scheduler::Process(int exe_time, int deadline) {
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Processing task with exe_time: %d, deadline: %d", exe_time, deadline);
    int slack_time = CalculateSlackTime(exe_time, deadline);
    int priority = GetPriority(slack_time);
    int version = GetVersion(slack_time, exe_time);

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Current task slack time: %d, version: %d, priority: %d", slack_time, version, priority);

    return priority;
}

int Scheduler::GetVersion(int slack_time, int exe_time) {
    if (slack_time >= exe_time) {
        return 1; // FP32
    } else if (slack_time >= exe_time - 10) {
        return 2; // FP16
    } else if (slack_time >= exe_time - 20) {
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

int Scheduler::CalculateSlackTime(int exe_time, int deadline) {
    // slack time = Di - Ci - t_cur
    int delay = GetNetworkDelay();
    int slack_time = deadline - exe_time - delay; 

    return slack_time;
}

int Scheduler::GetNetworkDelay() {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> delay_dist(30, 70); // 模拟网络延迟在30ms到70ms之间，则Slack Time范围在30ms - 70ms之间
    int delay = delay_dist(gen);
    return delay;
}

// void Scheduler::RegisterTask(std::shared_ptr<rclcpp::TimerBase> task) {
//     tasks.push_back(task);
// }

// void Scheduler::UpdatePriority(rclcpp::executors::SingleThreadedExecutor & exec){
//     for(auto& t : tasks){
//         int new_p = Process();
//         executor->set_callback_priority(t, new_p);
//     }
// }

void Scheduler::SetSingleThreadedExecutor(rclcpp::executors::SingleThreadedExecutor* exec) {
    executor = exec;
}