#include <stdlib.h>

#include "chunk.h"
#include "memory.h"
#include "value.h"

void init_chunk(Chunk *chunk) {
  chunk->count_ = 0;
  chunk->capacity_ = 0;
  chunk->code_ = NULL;
  chunk->lines_ = NULL;
  init_value_array(&chunk->constants_);
}

void free_chunk(Chunk *chunk) {
  FREE_ARRAY(uint8_t, chunk->code_, chunk->capacity_);
  FREE_ARRAY(int, chunk->lines_, chunk->capacity_); // runtime line dealloc
  free_value_array(&chunk->constants_);
  init_chunk(chunk); // zero out fields and leave in well-defined state
}

void write_chunk(Chunk *chunk, uint8_t byte, int line) {
  if (chunk->capacity_ < chunk->count_ + 1) {
    int old = chunk->capacity_;
    chunk->capacity_ = GROW_CAPACITY(old);
    chunk->code_ = GROW_ARRAY(uint8_t, chunk->code_, old, chunk->capacity_);
    chunk->lines_ = GROW_ARRAY(int, chunk->lines_, old, chunk->capacity_);
  }

  chunk->code_[chunk->count_] = byte;
  chunk->lines_[chunk->count_] = line;
  chunk->count_++;
}

int add_constant(Chunk *chunk, Value value) {
  write_value_array(&chunk->constants_, value);
  return chunk->constants_.count_ - 1;
}
