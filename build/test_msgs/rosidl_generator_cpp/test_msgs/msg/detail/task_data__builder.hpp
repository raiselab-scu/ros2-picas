// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from test_msgs:msg/TaskData.idl
// generated code does not contain a copyright notice

#ifndef TEST_MSGS__MSG__DETAIL__TASK_DATA__BUILDER_HPP_
#define TEST_MSGS__MSG__DETAIL__TASK_DATA__BUILDER_HPP_

#include "test_msgs/msg/detail/task_data__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace test_msgs
{

namespace msg
{

namespace builder
{

class Init_TaskData_deadline
{
public:
  explicit Init_TaskData_deadline(::test_msgs::msg::TaskData & msg)
  : msg_(msg)
  {}
  ::test_msgs::msg::TaskData deadline(::test_msgs::msg::TaskData::_deadline_type arg)
  {
    msg_.deadline = std::move(arg);
    return std::move(msg_);
  }

private:
  ::test_msgs::msg::TaskData msg_;
};

class Init_TaskData_execution_time
{
public:
  explicit Init_TaskData_execution_time(::test_msgs::msg::TaskData & msg)
  : msg_(msg)
  {}
  Init_TaskData_deadline execution_time(::test_msgs::msg::TaskData::_execution_time_type arg)
  {
    msg_.execution_time = std::move(arg);
    return Init_TaskData_deadline(msg_);
  }

private:
  ::test_msgs::msg::TaskData msg_;
};

class Init_TaskData_data2
{
public:
  explicit Init_TaskData_data2(::test_msgs::msg::TaskData & msg)
  : msg_(msg)
  {}
  Init_TaskData_execution_time data2(::test_msgs::msg::TaskData::_data2_type arg)
  {
    msg_.data2 = std::move(arg);
    return Init_TaskData_execution_time(msg_);
  }

private:
  ::test_msgs::msg::TaskData msg_;
};

class Init_TaskData_data1
{
public:
  Init_TaskData_data1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TaskData_data2 data1(::test_msgs::msg::TaskData::_data1_type arg)
  {
    msg_.data1 = std::move(arg);
    return Init_TaskData_data2(msg_);
  }

private:
  ::test_msgs::msg::TaskData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::test_msgs::msg::TaskData>()
{
  return test_msgs::msg::builder::Init_TaskData_data1();
}

}  // namespace test_msgs

#endif  // TEST_MSGS__MSG__DETAIL__TASK_DATA__BUILDER_HPP_
