// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from test_msgs:msg/UTime.idl
// generated code does not contain a copyright notice

#ifndef TEST_MSGS__MSG__DETAIL__U_TIME__BUILDER_HPP_
#define TEST_MSGS__MSG__DETAIL__U_TIME__BUILDER_HPP_

#include "test_msgs/msg/detail/u_time__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace test_msgs
{

namespace msg
{

namespace builder
{

class Init_UTime_usec
{
public:
  explicit Init_UTime_usec(::test_msgs::msg::UTime & msg)
  : msg_(msg)
  {}
  ::test_msgs::msg::UTime usec(::test_msgs::msg::UTime::_usec_type arg)
  {
    msg_.usec = std::move(arg);
    return std::move(msg_);
  }

private:
  ::test_msgs::msg::UTime msg_;
};

class Init_UTime_sec
{
public:
  Init_UTime_sec()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UTime_usec sec(::test_msgs::msg::UTime::_sec_type arg)
  {
    msg_.sec = std::move(arg);
    return Init_UTime_usec(msg_);
  }

private:
  ::test_msgs::msg::UTime msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::test_msgs::msg::UTime>()
{
  return test_msgs::msg::builder::Init_UTime_sec();
}

}  // namespace test_msgs

#endif  // TEST_MSGS__MSG__DETAIL__U_TIME__BUILDER_HPP_
