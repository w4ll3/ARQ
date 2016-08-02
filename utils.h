#ifndef UTILS_H_
#define UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct list {
	char *label;
	int address;
} list;

list *initialize_list();

void insert_list(list *ilist, char *label, int address, int *size);

void show_list(list *ilist, int size);

char *decimal_to_binary(int n);

#endif
