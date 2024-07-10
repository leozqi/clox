#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"

typedef enum {
  OP_RETURN,
} OpCode;

typedef struct {
  int count_;
  int capacity_;
  uint8_t *code_;
} Chunk;
// Dynamic bytecode array

void init_chunk(Chunk *chunk);
void free_chunk(Chunk *chunk);
void write_chunk(Chunk *chunk, uint8_t byte);

#endif
