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
int dummy_load_calib = 1;

void dummy_load(int load_ms) {
    int i, j;
    for (j = 0; j < dummy_load_calib * load_ms; j++)
        for (i = 0 ; i < DUMMY_LOAD_ITER; i++) 
            __asm__ volatile ("nop");
}

using namespace std::chrono_literals;

class StartNode : public rclcpp::Node
{
public:
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<test_msgs::msg::TaskData>::SharedPtr publisher_;

    StartNode(const std::string node_name, 
        const std::string pub_topic, 
        int exe_time,
        int period, 
        rclcpp::Scheduler& scheduler, 
        rclcpp::executors::SingleThreadedExecutor& exec) 
        : Node(node_name, rclcpp::NodeOptions().use_intra_process_comms(USE_INTRA_PROCESS_COMMS))
        , exe_time_(exe_time)
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
    int exe_time_;
    int period_;
    timeval create_timer;

    void dummy_task(int load) {
        int i;
        for (i = 0 ; i < load; i++) 
            __asm__ volatile ("nop");
    }

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
        RCLCPP_INFO(this->get_logger(), ("callback: " + name + " , priority: " + std::to_string(timer_->callback_priority)).c_str());

        auto message = generate_data();

        int priority = scheduler_.Process(message.execution_time, message.deadline);
        exec_.set_callback_priority(timer_, priority);

        dummy_load(exe_time_);

        if(publisher_) publisher_->publish(message);
    }        
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "PID: %ld run in ROS2.", gettid());

    rclcpp::executors::SingleThreadedExecutor exec1;
    rclcpp::Scheduler scheduler;
    scheduler.SetSingleThreadedExecutor(&exec1);

    // Naive way to calibrate dummy workload for current system
    while (1) {
        timeval ctime, ftime;
        int duration_us;
        gettimeofday(&ctime, NULL);
        dummy_load(100); // 100ms
        gettimeofday(&ftime, NULL);
        duration_us = (ftime.tv_sec - ctime.tv_sec) * 1000000 + (ftime.tv_usec - ctime.tv_usec);
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "dummy_load_calib: %d (duration_us: %d ns)", dummy_load_calib, duration_us);
        if (abs(duration_us - 100 * 1000) < 500) { // error margin: 500us
            break;
        }
        dummy_load_calib = 100 * 1000 * dummy_load_calib / duration_us;
        if (dummy_load_calib <= 0) dummy_load_calib = 1;
    }

    auto client1 = std::make_shared<StartNode>("Timer_callback1", "c1", 1000, 10000, scheduler, exec1);
    auto client2 = std::make_shared<StartNode>("Timer_callback2", "c2", 1000, 10000, scheduler, exec1);
    auto client3 = std::make_shared<StartNode>("Timer_callback3", "c3", 1000, 10000, scheduler, exec1);
    auto client4 = std::make_shared<StartNode>("Timer_callback4", "c4", 1000, 10000, scheduler, exec1);

#ifdef PICAS
    // Enable priority-based callback scheduling
    exec1.enable_callback_priority();
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "PiCAS priority-based callback scheduling: %s", exec1.callback_priority_enabled ? "Enabled" : "Disabled");

    // Set executor's RT priority and CPU allocation
    exec1.set_executor_priority_cpu(90, 5);
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "PiCAS executor 1's rt-priority %d and CPU %d", exec1.executor_priority, exec1.executor_cpu);

#endif

    exec1.add_node(client1);
    exec1.add_node(client2);
    exec1.add_node(client3);
    exec1.add_node(client4);

#ifdef PICAS

    // Set initial callback priorities
    exec1.set_callback_priority(client1->get_timer(), 4);
    exec1.set_callback_priority(client2->get_timer(), 3);
    exec1.set_callback_priority(client3->get_timer(), 2);
    exec1.set_callback_priority(client4->get_timer(), 1);
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
