#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <sys/time.h>
#include <random>
#include <cmath>
#include <cstdint>

// For ROS2RTF
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/syscall.h>
#include <mutex>

#include "trace_picas/trace.hpp"

#include "rclcpp/rclcpp.hpp"
#include "rclcpp/scheduler.hpp"
//#include "std_msgs/msg/string.hpp"
#include "test_msgs/msg/task_data.hpp"

using std::placeholders::_1;
//std::mutex mtx;

#define gettid() syscall(__NR_gettid)

//#define USE_INTRA_PROCESS_COMMS false
#define USE_INTRA_PROCESS_COMMS true

#define DUMMY_LOAD_ITER	1000

using namespace std::chrono_literals;

class StartNode : public rclcpp::Node
{
public:
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<test_msgs::msg::TaskData>::SharedPtr publisher_;
    StartNode(const std::string& name) : Node(name) {
        publisher_ = this->create_publisher<test_msgs::msg::TaskData>("task_topic", 10);
        timer_ = this->create_wall_timer(
            1s, std::bind(&StartNode::timer_callback, this));
    }
private:
    void timer_callback()
    {
        std::string name = this->get_name();            
        RCLCPP_INFO(this->get_logger(), ("callback: " + name).c_str());

        auto message = test_msgs::msg::TaskData();
        // generate random raw data and execution time
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> data_dist(0.0f, 1.0f);
        std::uniform_int_distribution<> exec_time_dist(30, 70);

        message.data1 = data_dist(gen);
        message.data2 = data_dist(gen);
        message.execution_time = exec_time_dist(gen);
        message.deadline = 100;

        publisher_->publish(message);
    }        
};

class ExecutorNode : public rclcpp::Node {
public:
    ExecutorNode() : Node("executor_node") {
        scheduler_ = std::make_shared<rclcpp::Scheduler>();
        
        for (int i = 1; i <= 4; i++) {
            auto callback = [this](const test_msgs::msg::TaskData::SharedPtr msg) {
                this->task_callback(msg);
            };

            auto sub = this->create_subscription<test_msgs::msg::TaskData>(
                "task_topic", 10, callback);
            subscriptions_.push_back(sub);
        }
    }

private:
    void task_callback(const test_msgs::msg::TaskData::SharedPtr msg) {
        rclcpp::Time now = this->now();
        // 生成，用scheduler
        double network_delay = (now - msg->stamp).seconds() * 1000; 
        
        scheduler_->SetBudgetTime(msg->deadline);
        int priority = scheduler_->Process();
        int version = scheduler_->GetVersion(
            msg->deadline - network_delay, 
            msg->execution_time
        );
        
        float result = execute_task(msg->data1, msg->data2, version);
        
        RCLCPP_INFO(this->get_logger(), 
            "Task executed: priority=%d, version=%d, result=%f", 
            priority, version, result);
    }

    float execute_task(float a, float b, int version) {
        switch (version) {
            case 1:  // FP32
                return a * b;
            case 2:  // FP16 - 模拟 FP16 精度
                {
                    // 将 float 转换为 int16_t 再转回来模拟 FP16 精度
                    int16_t a_fp16 = (int16_t)(a * 256);
                    int16_t b_fp16 = (int16_t)(b * 256);
                    return ((float)a_fp16 * (float)b_fp16) / (256.0f * 256.0f);
                }
            case 3:  // FP8
                {
                    // 将 float 转换为 int8_t 再转回来模拟 FP8 精度
                    int8_t a_fp8 = (int8_t)(a * 127);
                    int8_t b_fp8 = (int8_t)(b * 127);
                    return ((float)a_fp8 * (float)b_fp8) / (127.0f * 127.0f);
                }
            case 4:  // INT8
                {
                    int8_t a_int8 = (int8_t)(a * 127);
                    int8_t b_int8 = (int8_t)(b * 127);
                    return ((float)a_int8 * (float)b_int8) / (127.0f * 127.0f);
                }
            default:
                return a * b;
        }
    }

    std::shared_ptr<rclcpp::Scheduler> scheduler_;
    std::vector<rclcpp::Subscription<test_msgs::msg::TaskData>::SharedPtr> subscriptions_;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    
    // Create start nodes
    auto client1 = std::make_shared<StartNode>("node1");
    auto client2 = std::make_shared<StartNode>("node2");
    auto client3 = std::make_shared<StartNode>("node3");
    auto client4 = std::make_shared<StartNode>("node4");

    // Create executor node
    auto executor_node = std::make_shared<ExecutorNode>();

    // Create executor
    rclcpp::executors::SingleThreadedExecutor executor;
    executor.add_node(client1);
    executor.add_node(client2);
    executor.add_node(client3);
    executor.add_node(client4);
    executor.add_node(executor_node);
    
    executor.spin();
    
    rclcpp::shutdown();
    return 0;
}
