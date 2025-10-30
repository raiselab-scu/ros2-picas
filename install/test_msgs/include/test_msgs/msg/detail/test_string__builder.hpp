// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from test_msgs:msg/TestString.idl
// generated code does not contain a copyright notice

#ifndef TEST_MSGS__MSG__DETAIL__TEST_STRING__BUILDER_HPP_
#define TEST_MSGS__MSG__DETAIL__TEST_STRING__BUILDER_HPP_

#include "test_msgs/msg/detail/test_string__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace test_msgs
{

namespace msg
{

namespace builder
{

class Init_TestString_data
{
public:
  explicit Init_TestString_data(::test_msgs::msg::TestString & msg)
  : msg_(msg)
  {}
  ::test_msgs::msg::TestString data(::test_msgs::msg::TestString::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::test_msgs::msg::TestString msg_;
};

class Init_TestString_stamp
{
public:
  Init_TestString_stamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TestString_data stamp(::test_msgs::msg::TestString::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return Init_TestString_data(msg_);
  }

private:
  ::test_msgs::msg::TestString msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::test_msgs::msg::TestString>()
{
  return test_msgs::msg::builder::Init_TestString_stamp();
}

}  // namespace test_msgs

#endif  // TEST_MSGS__MSG__DETAIL__TEST_STRING__BUILDER_HPP_
