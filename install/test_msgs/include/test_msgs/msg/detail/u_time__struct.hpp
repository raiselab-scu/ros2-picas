// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from test_msgs:msg/UTime.idl
// generated code does not contain a copyright notice

#ifndef TEST_MSGS__MSG__DETAIL__U_TIME__STRUCT_HPP_
#define TEST_MSGS__MSG__DETAIL__U_TIME__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__test_msgs__msg__UTime __attribute__((deprecated))
#else
# define DEPRECATED__test_msgs__msg__UTime __declspec(deprecated)
#endif

namespace test_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct UTime_
{
  using Type = UTime_<ContainerAllocator>;

  explicit UTime_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sec = 0l;
      this->usec = 0ul;
    }
  }

  explicit UTime_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sec = 0l;
      this->usec = 0ul;
    }
  }

  // field types and members
  using _sec_type =
    int32_t;
  _sec_type sec;
  using _usec_type =
    uint32_t;
  _usec_type usec;

  // setters for named parameter idiom
  Type & set__sec(
    const int32_t & _arg)
  {
    this->sec = _arg;
    return *this;
  }
  Type & set__usec(
    const uint32_t & _arg)
  {
    this->usec = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    test_msgs::msg::UTime_<ContainerAllocator> *;
  using ConstRawPtr =
    const test_msgs::msg::UTime_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<test_msgs::msg::UTime_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<test_msgs::msg::UTime_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      test_msgs::msg::UTime_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<test_msgs::msg::UTime_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      test_msgs::msg::UTime_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<test_msgs::msg::UTime_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<test_msgs::msg::UTime_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<test_msgs::msg::UTime_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__test_msgs__msg__UTime
    std::shared_ptr<test_msgs::msg::UTime_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__test_msgs__msg__UTime
    std::shared_ptr<test_msgs::msg::UTime_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UTime_ & other) const
  {
    if (this->sec != other.sec) {
      return false;
    }
    if (this->usec != other.usec) {
      return false;
    }
    return true;
  }
  bool operator!=(const UTime_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UTime_

// alias to use template instance with default allocator
using UTime =
  test_msgs::msg::UTime_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace test_msgs

#endif  // TEST_MSGS__MSG__DETAIL__U_TIME__STRUCT_HPP_
