// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from test_msgs:msg/TestString.idl
// generated code does not contain a copyright notice
#include "test_msgs/msg/detail/test_string__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `stamp`
#include "test_msgs/msg/detail/u_time__functions.h"
// Member `data`
#include "rosidl_runtime_c/string_functions.h"

bool
test_msgs__msg__TestString__init(test_msgs__msg__TestString * msg)
{
  if (!msg) {
    return false;
  }
  // stamp
  if (!test_msgs__msg__UTime__init(&msg->stamp)) {
    test_msgs__msg__TestString__fini(msg);
    return false;
  }
  // data
  if (!rosidl_runtime_c__String__init(&msg->data)) {
    test_msgs__msg__TestString__fini(msg);
    return false;
  }
  return true;
}

void
test_msgs__msg__TestString__fini(test_msgs__msg__TestString * msg)
{
  if (!msg) {
    return;
  }
  // stamp
  test_msgs__msg__UTime__fini(&msg->stamp);
  // data
  rosidl_runtime_c__String__fini(&msg->data);
}

bool
test_msgs__msg__TestString__are_equal(const test_msgs__msg__TestString * lhs, const test_msgs__msg__TestString * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // stamp
  if (!test_msgs__msg__UTime__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  // data
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->data), &(rhs->data)))
  {
    return false;
  }
  return true;
}

bool
test_msgs__msg__TestString__copy(
  const test_msgs__msg__TestString * input,
  test_msgs__msg__TestString * output)
{
  if (!input || !output) {
    return false;
  }
  // stamp
  if (!test_msgs__msg__UTime__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  // data
  if (!rosidl_runtime_c__String__copy(
      &(input->data), &(output->data)))
  {
    return false;
  }
  return true;
}

test_msgs__msg__TestString *
test_msgs__msg__TestString__create()
{
  test_msgs__msg__TestString * msg = (test_msgs__msg__TestString *)malloc(sizeof(test_msgs__msg__TestString));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(test_msgs__msg__TestString));
  bool success = test_msgs__msg__TestString__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
test_msgs__msg__TestString__destroy(test_msgs__msg__TestString * msg)
{
  if (msg) {
    test_msgs__msg__TestString__fini(msg);
  }
  free(msg);
}


bool
test_msgs__msg__TestString__Sequence__init(test_msgs__msg__TestString__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  test_msgs__msg__TestString * data = NULL;
  if (size) {
    data = (test_msgs__msg__TestString *)calloc(size, sizeof(test_msgs__msg__TestString));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = test_msgs__msg__TestString__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        test_msgs__msg__TestString__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
test_msgs__msg__TestString__Sequence__fini(test_msgs__msg__TestString__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      test_msgs__msg__TestString__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

test_msgs__msg__TestString__Sequence *
test_msgs__msg__TestString__Sequence__create(size_t size)
{
  test_msgs__msg__TestString__Sequence * array = (test_msgs__msg__TestString__Sequence *)malloc(sizeof(test_msgs__msg__TestString__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = test_msgs__msg__TestString__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
test_msgs__msg__TestString__Sequence__destroy(test_msgs__msg__TestString__Sequence * array)
{
  if (array) {
    test_msgs__msg__TestString__Sequence__fini(array);
  }
  free(array);
}

bool
test_msgs__msg__TestString__Sequence__are_equal(const test_msgs__msg__TestString__Sequence * lhs, const test_msgs__msg__TestString__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!test_msgs__msg__TestString__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
test_msgs__msg__TestString__Sequence__copy(
  const test_msgs__msg__TestString__Sequence * input,
  test_msgs__msg__TestString__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(test_msgs__msg__TestString);
    test_msgs__msg__TestString * data =
      (test_msgs__msg__TestString *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!test_msgs__msg__TestString__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          test_msgs__msg__TestString__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!test_msgs__msg__TestString__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
