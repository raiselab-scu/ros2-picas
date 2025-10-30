// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from test_msgs:msg/UTime.idl
// generated code does not contain a copyright notice

#ifndef TEST_MSGS__MSG__DETAIL__U_TIME__STRUCT_H_
#define TEST_MSGS__MSG__DETAIL__U_TIME__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/UTime in the package test_msgs.
typedef struct test_msgs__msg__UTime
{
  int32_t sec;
  uint32_t usec;
} test_msgs__msg__UTime;

// Struct for a sequence of test_msgs__msg__UTime.
typedef struct test_msgs__msg__UTime__Sequence
{
  test_msgs__msg__UTime * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} test_msgs__msg__UTime__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TEST_MSGS__MSG__DETAIL__U_TIME__STRUCT_H_
