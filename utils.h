#ifndef UTILS_H_
#define UTILS_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	char *label;
	int laddress;
} list;

list *initialize_list();

void insert_list(list *llist, char *label, int laddress, int *lcount);

void show_list(list *llist, int size);

#endif
