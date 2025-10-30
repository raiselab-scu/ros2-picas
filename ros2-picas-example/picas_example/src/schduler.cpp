#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <sys/time.h>
#include <random>
#include <cmath>

// QoS版本
// v1, v2, v3, v4：暂时使用不同计算精度，比如FP32，FP16，INT8

// 每个任务进来后，首先随机生成一个Network Delay，然后根据delay计算出Slack Time
// 假设每个任务计算Budget Time的时间为100ms
// 计算完后，需要根据Slack Time来计算任务的优先级，以及选择不同的QoS版本
// 有前提条件，即该任务需要多久完成，目前先假设
class Scheduler {
public:
    Scheduler() {}
    ~Scheduler() {}

    void Process();
    int GetVersion();
    int GetPriority();
    int GetNetworkDelay();
    int CalculateSlackTime();

    void SetBudgetTime(int time) { TaskBudgetTime = time; }

private:
    int TaskBudgetTime = 100;
};

void Scheduler::Process() {
    int slack_time = CalculateSlackTime();

    int version = GetVersion(slack_time, 55); // 暂时假设任务需要55ms完成
    int priority = GetPriority(slack_time);
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
    // 假设优先级范围为1-98，Slack Time越大，优先级越低
    int priority = 1 + (98 - 1) * (100 - slack_time) / 100;
    if (priority < 1) priority = 1;
    if (priority > 98) priority = 98;
    return priority;
}

int Scheduler::CalculateSlackTime() {
    int network_delay = GetNetworkDelay();
    int slack_time = TaskBudgetTime - network_delay;

    return slack_time
}

int Scheduler::GetNetworkDelay() {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> delay_dist(30, 70); // 模拟网络延迟在30ms到70ms之间，则Slack Time范围在30ms - 70ms之间
    int delay = delay_dist(gen);
    return delay;
}