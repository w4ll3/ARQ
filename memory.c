#include "memory.h"

memory *initialize_mem(int size) {
	memory *mem = (memory*) malloc(sizeof(memory));
	mem -> data = (char**) malloc(size * sizeof(memory));
	for (int i = 0; i < size; i++)
		mem -> data[i] = (char*) calloc(32, sizeof(char));

	mem -> size = size;
	return mem;
}

void print_mem(memory mem) {
	for (size_t i = 0; i < 30; i++) {
		for (size_t j = 0; j < 32; j++)
			printf("%4d", j);
		printf("\n");
		for (size_t j = 0; j < 32; j++) {
			if(mem.data[i][j] == '\0') {
				printf("%4c", '9');
			} else {
				printf("%4c", mem.data[i][j]);
			}
		}
		printf("\n");
	}
}

void copy(memory *mem, char *str, int mbeggin, int mend, int pos, int sbeggin) {
	for (int i = mbeggin, j = sbeggin; i <= mend; i++, j++) {
		mem -> data[pos][i] = str[j];
	}
	printf("\n");
}

void set_address(list *llist, list *olist, int lcount, int ocount, memory *mem) {
	for (int i = 0; i < ocount; i++) {
		for (int k = 0; k < lcount; k++) {
			if(strcmp(olist[i].label, llist[k].label) == 0) {
				switch(mem -> data[olist[i].address][0]) {
					case '0': {
						if(mem -> data[olist[i].address][1]) {
							copy(mem, decimal_to_binary(llist[k].address), 11, 31, olist[i].address, 0);
						}
						break;
					}

					case '1': {
						if(mem -> data[olist[i].address][1] == '0') {
							copy(mem, decimal_to_binary(llist[k].address), 17, 31, olist[i].address, 0);
							break;
						} else if (mem -> data[olist[i].address][1] == '1') {
							copy(mem, decimal_to_binary(llist[k].address), 6, 31, olist[i].address, 0);
							break;
						}
						break;
					}
				}
			} else {
			printf("\nInstruction calls inexistent label.\n");
			}
		}
	}
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
