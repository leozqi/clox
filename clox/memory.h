#ifndef clox_memory_h
#define clox_memory_h

#include "common.h"

// Grow dynamic array to 8 bytes if not 8 bytes, else double it.
#define GROW_CAPACITY(capacity) ((capacity) < 8 ? 8 : (capacity)*2)

#define GROW_ARRAY(type, pointer, old_count, new_count)                        \
  (type *)clox_realloc(pointer, sizeof(type) * (old_count),                    \
                       sizeof(type) * (new_count))

#define FREE_ARRAY(type, pointer, old_count)                                   \
  clox_realloc(pointer, sizeof(type) * old_count, 0)

void *clox_realloc(void *pointer, size_t old_size, size_t new_size);

#endif
