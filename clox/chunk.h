#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

typedef enum {
  OP_CONSTANT,
  OP_RETURN,
} OpCode;

typedef struct {
  int count_;
  int capacity_;
  uint8_t *code_;
  ValueArray constants_;
} Chunk;
// Dynamic bytecode array

void init_chunk(Chunk *chunk);
void free_chunk(Chunk *chunk);
void write_chunk(Chunk *chunk, uint8_t byte);

int add_constant(Chunk *chunk, Value value);

#endif
