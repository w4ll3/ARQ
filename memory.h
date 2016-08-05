#ifndef MEMORY_H_
#define MEMORY_H_
#define MEMSIZE 512
#define EMPTY_POS "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

typedef struct {
	char **data;
	int size;
} memory;

memory *initialize_mem(int size);

void print_mem(memory mem);

void copy(memory *mem, char *str, int mbeggin, int mend, int pos, int sbeggin);

void set_address(list *llist, list *olist, int lcount, int ocount, memory *mem);

#endif
