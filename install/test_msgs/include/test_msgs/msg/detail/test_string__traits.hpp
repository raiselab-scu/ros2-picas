// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from test_msgs:msg/TestString.idl
// generated code does not contain a copyright notice

#ifndef TEST_MSGS__MSG__DETAIL__TEST_STRING__TRAITS_HPP_
#define TEST_MSGS__MSG__DETAIL__TEST_STRING__TRAITS_HPP_

#include "test_msgs/msg/detail/test_string__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

// Include directives for member types
// Member 'stamp'
#include "test_msgs/msg/detail/u_time__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const test_msgs::msg::TestString & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_yaml(msg.stamp, out, indentation + 2);
  }

  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data: ";
    value_to_yaml(msg.data, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const test_msgs::msg::TestString & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<test_msgs::msg::TestString>()
{
  return "test_msgs::msg::TestString";
}

template<>
inline const char * name<test_msgs::msg::TestString>()
{
  return "test_msgs/msg/TestString";
}

template<>
struct has_fixed_size<test_msgs::msg::TestString>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<test_msgs::msg::TestString>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<test_msgs::msg::TestString>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TEST_MSGS__MSG__DETAIL__TEST_STRING__TRAITS_HPP_
