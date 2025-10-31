// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from test_msgs:msg/TaskData.idl
// generated code does not contain a copyright notice

#ifndef TEST_MSGS__MSG__DETAIL__TASK_DATA__TRAITS_HPP_
#define TEST_MSGS__MSG__DETAIL__TASK_DATA__TRAITS_HPP_

#include "test_msgs/msg/detail/task_data__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const test_msgs::msg::TaskData & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: data1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data1: ";
    value_to_yaml(msg.data1, out);
    out << "\n";
  }

  // member: data2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data2: ";
    value_to_yaml(msg.data2, out);
    out << "\n";
  }

  // member: execution_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "execution_time: ";
    value_to_yaml(msg.execution_time, out);
    out << "\n";
  }

  // member: deadline
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "deadline: ";
    value_to_yaml(msg.deadline, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const test_msgs::msg::TaskData & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<test_msgs::msg::TaskData>()
{
  return "test_msgs::msg::TaskData";
}

template<>
inline const char * name<test_msgs::msg::TaskData>()
{
  return "test_msgs/msg/TaskData";
}

template<>
struct has_fixed_size<test_msgs::msg::TaskData>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<test_msgs::msg::TaskData>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<test_msgs::msg::TaskData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TEST_MSGS__MSG__DETAIL__TASK_DATA__TRAITS_HPP_
