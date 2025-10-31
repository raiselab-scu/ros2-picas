// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from test_msgs:msg/TaskData.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "test_msgs/msg/detail/task_data__rosidl_typesupport_introspection_c.h"
#include "test_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "test_msgs/msg/detail/task_data__functions.h"
#include "test_msgs/msg/detail/task_data__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void TaskData__rosidl_typesupport_introspection_c__TaskData_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  test_msgs__msg__TaskData__init(message_memory);
}

void TaskData__rosidl_typesupport_introspection_c__TaskData_fini_function(void * message_memory)
{
  test_msgs__msg__TaskData__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember TaskData__rosidl_typesupport_introspection_c__TaskData_message_member_array[4] = {
  {
    "data1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(test_msgs__msg__TaskData, data1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "data2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(test_msgs__msg__TaskData, data2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "execution_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(test_msgs__msg__TaskData, execution_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "deadline",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(test_msgs__msg__TaskData, deadline),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers TaskData__rosidl_typesupport_introspection_c__TaskData_message_members = {
  "test_msgs__msg",  // message namespace
  "TaskData",  // message name
  4,  // number of fields
  sizeof(test_msgs__msg__TaskData),
  TaskData__rosidl_typesupport_introspection_c__TaskData_message_member_array,  // message members
  TaskData__rosidl_typesupport_introspection_c__TaskData_init_function,  // function to initialize message memory (memory has to be allocated)
  TaskData__rosidl_typesupport_introspection_c__TaskData_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t TaskData__rosidl_typesupport_introspection_c__TaskData_message_type_support_handle = {
  0,
  &TaskData__rosidl_typesupport_introspection_c__TaskData_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_test_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, test_msgs, msg, TaskData)() {
  if (!TaskData__rosidl_typesupport_introspection_c__TaskData_message_type_support_handle.typesupport_identifier) {
    TaskData__rosidl_typesupport_introspection_c__TaskData_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &TaskData__rosidl_typesupport_introspection_c__TaskData_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
