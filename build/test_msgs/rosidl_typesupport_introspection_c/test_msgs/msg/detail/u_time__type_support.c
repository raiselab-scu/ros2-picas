// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from test_msgs:msg/UTime.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "test_msgs/msg/detail/u_time__rosidl_typesupport_introspection_c.h"
#include "test_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "test_msgs/msg/detail/u_time__functions.h"
#include "test_msgs/msg/detail/u_time__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void UTime__rosidl_typesupport_introspection_c__UTime_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  test_msgs__msg__UTime__init(message_memory);
}

void UTime__rosidl_typesupport_introspection_c__UTime_fini_function(void * message_memory)
{
  test_msgs__msg__UTime__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember UTime__rosidl_typesupport_introspection_c__UTime_message_member_array[2] = {
  {
    "sec",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(test_msgs__msg__UTime, sec),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "usec",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(test_msgs__msg__UTime, usec),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers UTime__rosidl_typesupport_introspection_c__UTime_message_members = {
  "test_msgs__msg",  // message namespace
  "UTime",  // message name
  2,  // number of fields
  sizeof(test_msgs__msg__UTime),
  UTime__rosidl_typesupport_introspection_c__UTime_message_member_array,  // message members
  UTime__rosidl_typesupport_introspection_c__UTime_init_function,  // function to initialize message memory (memory has to be allocated)
  UTime__rosidl_typesupport_introspection_c__UTime_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t UTime__rosidl_typesupport_introspection_c__UTime_message_type_support_handle = {
  0,
  &UTime__rosidl_typesupport_introspection_c__UTime_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_test_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, test_msgs, msg, UTime)() {
  if (!UTime__rosidl_typesupport_introspection_c__UTime_message_type_support_handle.typesupport_identifier) {
    UTime__rosidl_typesupport_introspection_c__UTime_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &UTime__rosidl_typesupport_introspection_c__UTime_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
