
// QoS版本
// v1, v2, v3, v4：暂时使用不同计算精度，比如FP32，FP16，INT8

// 每个任务进来后，首先随机生成一个Network Delay，然后根据delay计算出Slack Time
// 假设每个任务计算Budget Time的时间为100ms
// 计算完后，需要根据Slack Time来计算任务的优先级，以及选择不同的QoS版本
// 有前提条件，即该任务需要多久完成，目前先假设

#ifndef RCLCPP__SCHEDULER_HPP_
#define RCLCPP__SCHEDULER_HPP_

namespace rclcpp
{
class Scheduler {
public:
    Scheduler();
    ~Scheduler();

    void Init();
    int Process();
    int GetVersion(int slack_time, int expect_complete_time);
    int GetPriority(int slack_time);
    int GetNetworkDelay();
    int CalculateSlackTime();

    void SetBudgetTime(int time) { TaskBudgetTime = time; }

private:
    int TaskBudgetTime;
};

} // namespace rclcpp

#endif  // RCLCPP__SCHEDULER_HPP_