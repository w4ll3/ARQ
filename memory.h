#ifndef MEMORY_H_
#define MEMORY_H_
#define MEMSIZE 512

#include "utils.h"

typedef struct {
	char **data;
	int size;
} memory;

memory *initiate_mem(int size);

void print_mem(memory mem);

void copy(memory *mem, char *str, int mbeggin, int mend, int pos, int sbeggin);

void set_address(list *llist, list *olist, int lcount, int ocount, memory *mem);

#endif
