#include <stdlib.h>

#include "memory.h"

void *clox_realloc(void *pointer, size_t old_size, size_t new_size) {
  if (new_size == 0) {
    free(pointer);
    return NULL;
  }

  // when old_size = 0, realloc() is equivalent to calling malloc
  void *result = realloc(pointer, new_size);

  // nothing useful to do; abort process immediately
  if (result == NULL)
    exit(1);

  return result;
}
