#ifndef clox_value_h
#define clox_value_h

#include "common.h"

// Associate constant pool with each compiled class.
typedef double Value;

typedef struct {
  int capacity_;
  int count_;
  Value *values_;
} ValueArray;
// Constant pool for values.
// To load a constant, lookup its index in here.

void init_value_array(ValueArray *array);
void write_value_array(ValueArray *array, Value value);
void free_value_array(ValueArray *array);

void print_value(Value value);

#endif
