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

char *decimal_to_binary(int n) {
	int aux, count = 0;
	char *bin;
	bin = (char*) malloc(32+1);
	for(int c = 31; c >= 0; c--) {
		aux = n >> c;
		if(aux & 1)
			*(bin + count) = 1 + '0';
		else
			*(bin + count) = 0 + '0';
		count++;
	}
	*(bin+count) = '\0';
	return bin;
}
