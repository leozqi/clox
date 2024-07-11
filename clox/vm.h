#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"
#include "value.h"

#define STACK_MAX 256

typedef struct {
  Chunk *chunk_;
  uint8_t *ip_;
  Value stack_[STACK_MAX];
  Value *stack_top_;
} VM;
// ip_ always points to instruction to be executed

typedef enum {
  INTERPRET_OK,
  INTERPRET_COMPILE_ERROR,
  INTERPRET_RUNTIME_ERROR
} InterpretResult;

void init_vm();
void free_vm();

InterpretResult interpret(Chunk *chunk);

void push(Value value);
Value pop();

#endif
