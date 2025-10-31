// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from test_msgs:msg/TaskData.idl
// generated code does not contain a copyright notice

#ifndef TEST_MSGS__MSG__DETAIL__TASK_DATA__STRUCT_H_
#define TEST_MSGS__MSG__DETAIL__TASK_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/TaskData in the package test_msgs.
typedef struct test_msgs__msg__TaskData
{
  float data1;
  float data2;
  int32_t execution_time;
  int32_t deadline;
} test_msgs__msg__TaskData;

// Struct for a sequence of test_msgs__msg__TaskData.
typedef struct test_msgs__msg__TaskData__Sequence
{
  test_msgs__msg__TaskData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} test_msgs__msg__TaskData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TEST_MSGS__MSG__DETAIL__TASK_DATA__STRUCT_H_
