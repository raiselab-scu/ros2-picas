#ifndef RCLCPP__SCHEDULER_HPP_
#define RCLCPP__SCHEDULER_HPP_

#include <memory>
#include <vector>
#include "rclcpp/rclcpp.hpp"
#include "rclcpp/executors/single_threaded_executor.hpp"

namespace rclcpp
{
class Scheduler {
public:
    Scheduler();
    ~Scheduler();

    int Process(int exe_time, int deadline);
    int CalculateSlackTime(int exe_time, int deadline);

    int GetVersion(int slack_time, int exe_time);
    int GetPriority(int slack_time);
    int GetNetworkDelay();

    void SetSingleThreadedExecutor(rclcpp::executors::SingleThreadedExecutor* exec);

    // void RegisterTask(std::shared_ptr<rclcpp::TimerBase> task);
    // void UpdatePriority(rclcpp::executors::SingleThreadedExecutor & exec);

private:
    std::vector<std::shared_ptr<rclcpp::TimerBase>> tasks;
    rclcpp::executors::SingleThreadedExecutor* executor;
};

} // namespace rclcpp

#endif  // RCLCPP__SCHEDULER_HPP_