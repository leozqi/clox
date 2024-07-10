#ifndef clox_debug_h
#define clox_debug_h

#include "chunk.h"

void disassemble_chunk(Chunk *chunk, const char *name);

// Disassembles a single instruction in the chunk
int disassemble_instruction(Chunk *chunk, int offset);

#endif
