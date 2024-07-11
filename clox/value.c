#include <stdio.h>

#include "memory.h"
#include "value.h"

void init_value_array(ValueArray *array) {
  array->values_ = NULL;
  array->capacity_ = 0;
  array->count_ = 0;
}

void write_value_array(ValueArray *array, Value value) {
  if (array->capacity_ < array->count_ + 1) {
    int old = array->capacity_;
    array->capacity_ = GROW_CAPACITY(old);
    array->values_ = GROW_ARRAY(Value, array->values_, old, array->capacity_);
  }

  array->values_[array->count_] = value;
  array->count_++;
}

void free_value_array(ValueArray *array) {
  FREE_ARRAY(Value, array->values_, array->capacity_);
  init_value_array(array);
}

void print_value(Value value) { printf("%g", value); }
