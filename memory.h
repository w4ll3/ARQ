#ifndef MEMORY_H_
#define MEMORY_H_
#define MEMSIZE 512

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct memory {
	char **data;
	int size;
} memory;

memory *initialize_mem(int size);

void set_opcode(char *opcode, memory *mem, int pos);

// void dec_to_bin();
//
// void bin_to_dec();

void right_shift(memory *mem);

void left_shift(memory *mem);

void set_format1();

#endif
