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

    StartNode(const std::string node_name, 
        const std::string pub_topic, 
        int period, 
        rclcpp::Scheduler& scheduler, 
        rclcpp::executors::SingleThreadedExecutor& exec) 
        : Node(node_name, rclcpp::NodeOptions().use_intra_process_comms(USE_INTRA_PROCESS_COMMS))
        , period_(period)
        , scheduler_(scheduler)
        , exec_(exec)
    {
        publisher_ = this->create_publisher<test_msgs::msg::TaskData>(pub_topic, 1);

        if (period_ == 10000)
            timer_ = this->create_wall_timer(10000ms, std::bind(&StartNode::timer_callback, this));
        else
            timer_ = this->create_wall_timer(3000ms, std::bind(&StartNode::timer_callback, this));

        gettimeofday(&create_timer, NULL);
        RCLCPP_INFO(this->get_logger(), "Create wall timer at %ld", create_timer.tv_sec*1000+create_timer.tv_usec/1000);
    }

    rclcpp::TimerBase::SharedPtr get_timer(){ return timer_; }
    
private:
    rclcpp::Scheduler& scheduler_;
    rclcpp::executors::SingleThreadedExecutor& exec_;
    int period_;
    timeval create_timer;

    test_msgs::msg::TaskData generate_data(){
        auto message = test_msgs::msg::TaskData();

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> data_dist(0.0f, 1.0f);
        std::uniform_int_distribution<> exec_time_dist(30, 70);

        message.data1 = data_dist(gen);
        message.data2 = data_dist(gen);
        message.execution_time = exec_time_dist(gen);
        message.deadline = 100;

        return message;
    }

    void timer_callback()
    {
        std::string name = this->get_name();            
        RCLCPP_INFO(this->get_logger(), ("callback: " + name).c_str());

        auto message = generate_data();

        int priority = scheduler_.Process(message.execution_time, message.deadline);
        exec_.set_callback_priority(timer_, priority);

        if(publisher_) publisher_->publish(message);
    }        
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "PID: %ld run in ROS2.", gettid());

    rclcpp::executors::SingleThreadedExecutor exec1;
    rclcpp::Scheduler scheduler;
    scheduler.SetSingleThreadedExecutor(&exec1);

    auto client1 = std::make_shared<StartNode>("Timer_callback1", "c1", 3000, scheduler, exec1);
    auto client2 = std::make_shared<StartNode>("Timer_callback2", "c2", 3000, scheduler, exec1);
    auto client3 = std::make_shared<StartNode>("Timer_callback3", "c3", 3000, scheduler, exec1);
    auto client4 = std::make_shared<StartNode>("Timer_callback4", "c4", 3000, scheduler, exec1);

#ifdef PICAS
    exec1.enable_callback_priority();
    exec1.set_executor_priority_cpu(90, 5);

    exec1.add_node(client1);
    exec1.add_node(client2);
    exec1.add_node(client3);
    exec1.add_node(client4);

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Timer_callback1->priority: %d", client1->get_timer()->callback_priority);
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Timer_callback2->priority: %d", client2->get_timer()->callback_priority);
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Timer_callback3->priority: %d", client3->get_timer()->callback_priority);
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Timer_callback4->priority: %d", client4->get_timer()->callback_priority);

    std::thread spinThread1(&rclcpp::executors::SingleThreadedExecutor::spin_rt, &exec1);
#else
    std::thread spinThread1(&rclcpp::executors::SingleThreadedExecutor::spin, &exec1);
#endif
    spinThread1.join();

    exec1.remove_node(client1);
    exec1.remove_node(client2);
    exec1.remove_node(client3);
    exec1.remove_node(client4);

    rclcpp::shutdown();
    return 0;
}
