#include "utils.h"

list *initialize_list() {
	list *ilist = (list*) malloc(sizeof(list) * 4096);
	return ilist;
}

void insert_list(list *ilist, char *label, int address, int *size) {
	ilist[*size].label = label;
	ilist[*size].address = address;
	*size += 1;
}

void show_list(list *ilist, int size) {
	int i = 0;
	while(i < size) {
		printf("[%s]  [%d]\n", ilist[i].label, ilist[i].address);
		i++;
	}
	printf("\n");
}
