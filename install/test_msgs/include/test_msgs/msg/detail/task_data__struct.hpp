// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from test_msgs:msg/TaskData.idl
// generated code does not contain a copyright notice

#ifndef TEST_MSGS__MSG__DETAIL__TASK_DATA__STRUCT_HPP_
#define TEST_MSGS__MSG__DETAIL__TASK_DATA__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__test_msgs__msg__TaskData __attribute__((deprecated))
#else
# define DEPRECATED__test_msgs__msg__TaskData __declspec(deprecated)
#endif

namespace test_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TaskData_
{
  using Type = TaskData_<ContainerAllocator>;

  explicit TaskData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->data1 = 0.0f;
      this->data2 = 0.0f;
      this->execution_time = 0l;
      this->deadline = 0l;
    }
  }

  explicit TaskData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->data1 = 0.0f;
      this->data2 = 0.0f;
      this->execution_time = 0l;
      this->deadline = 0l;
    }
  }

  // field types and members
  using _data1_type =
    float;
  _data1_type data1;
  using _data2_type =
    float;
  _data2_type data2;
  using _execution_time_type =
    int32_t;
  _execution_time_type execution_time;
  using _deadline_type =
    int32_t;
  _deadline_type deadline;

  // setters for named parameter idiom
  Type & set__data1(
    const float & _arg)
  {
    this->data1 = _arg;
    return *this;
  }
  Type & set__data2(
    const float & _arg)
  {
    this->data2 = _arg;
    return *this;
  }
  Type & set__execution_time(
    const int32_t & _arg)
  {
    this->execution_time = _arg;
    return *this;
  }
  Type & set__deadline(
    const int32_t & _arg)
  {
    this->deadline = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    test_msgs::msg::TaskData_<ContainerAllocator> *;
  using ConstRawPtr =
    const test_msgs::msg::TaskData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<test_msgs::msg::TaskData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<test_msgs::msg::TaskData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      test_msgs::msg::TaskData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<test_msgs::msg::TaskData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      test_msgs::msg::TaskData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<test_msgs::msg::TaskData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<test_msgs::msg::TaskData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<test_msgs::msg::TaskData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__test_msgs__msg__TaskData
    std::shared_ptr<test_msgs::msg::TaskData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__test_msgs__msg__TaskData
    std::shared_ptr<test_msgs::msg::TaskData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TaskData_ & other) const
  {
    if (this->data1 != other.data1) {
      return false;
    }
    if (this->data2 != other.data2) {
      return false;
    }
    if (this->execution_time != other.execution_time) {
      return false;
    }
    if (this->deadline != other.deadline) {
      return false;
    }
    return true;
  }
  bool operator!=(const TaskData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TaskData_

// alias to use template instance with default allocator
using TaskData =
  test_msgs::msg::TaskData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace test_msgs

#endif  // TEST_MSGS__MSG__DETAIL__TASK_DATA__STRUCT_HPP_
