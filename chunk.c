#include <stdlib.h>

#include "chunk.h"
#include "memory.h"

void init_chunk(Chunk *chunk) {
  chunk->count_ = 0;
  chunk->capacity_ = 0;
  chunk->code_ = NULL;
}

void free_chunk(Chunk *chunk) {
  FREE_ARRAY(uint8_t, chunk->code_, chunk->capacity_);
  init_chunk(chunk); // zero out fields and leave in well-defined state
}

void write_chunk(Chunk *chunk, uint8_t byte) {
  if (chunk->capacity_ < chunk->count_ + 1) {
    int old = chunk->capacity_;
    chunk->capacity_ = GROW_CAPACITY(old);
    chunk->code_ = GROW_ARRAY(uint8_t, chunk->code_, old, chunk->capacity_);
  }

  chunk->code[chunk->count_] = byte;
  chunk->count_++;
}
