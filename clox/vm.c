#include <stdio.h>

#include "common.h"
#include "debug.h"
#include "vm.h"

VM vm;

static void reset_stack() { vm.stack_top_ = vm.stack_; }

void init_vm() { reset_stack() }

void free_vm() {}

void push(Value value) {
  *vm.stack_top_ = value;
  vm.stack_top_++;
}

Value pop() {
  vm.stack_top_--;
  return *vm.stack_top_;
}

InterpretResult interpret(Chunk *chunk) {
  vm.chunk_ = chunk;
  vm.ip_ = vm.chunk->code_;
  return run();
}

static InterpretResult run() {
#define READ_BYTE() (*vm.ip_++)
#define READ_CONSTANT() (vm.chunk_->constants_.values_[READ_BYTE()])

  for (;;) {
#ifdef DEBUG_TRACE_EXECUTION
    printf("          ");
    for (Value *slot = vm.stack_; slot < vm.stack_top_; slot++) {
      printf("[ ");
      printValue(*slot);
      printf(" ]");
    }
    printf("\n");
    disassemble_instruction(vm.chunk_, (int)(vm.ip_ - vm.chunk_->code_));
#endif

    uint8_t instruction;
    switch (instruction = READ_BYTE()) {
    case OP_CONSTANT: {
      Value constant = READ_CONSTANT();
      push(constant);
      break;
    }
    case OP_RETURN: {
      printValue(pop());
      printf("\n");
      return INTERPRET_OK;
    }
    }
  }
#undef READ_BYTE
#undef READ_CONSTANT
}
