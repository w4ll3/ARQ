#include "memory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

memory *initiate_mem(int size) {
	memory *mem = (memory*) malloc(sizeof(memory));
	mem -> data = (char**) malloc(size * sizeof(memory));
	for (int i = 0; i < size; i++)
		mem -> data[i] = (char*) calloc(32, sizeof(char));

	mem -> size = size;
	return mem;
}

void print_mem(memory mem) {
	int counter = 0;
	printf(".");
	print_minus(80);
	printf(".\n");
	for (int i = 0; i < mem.size; i++) {
		if (strcmp(mem.data[i], EMPTY_POS) == 0) {
			counter++;
		} else {
			printf("|[%.4d]\t\t", i);
			for (int j = 0; j < 32; j++) {
				if(mem.data[i][j] == '\0') {
					printf("%2c", ' ');
				} else {
					printf("%2c", mem.data[i][j]);
				}
			}
			printf(" |\n");
		}
	}
	printf("|\t\t\tHidding %d empty positions\t\t\t\t |\n", counter - 1);
	printf("*");
	print_minus(80);
	printf("*\n");
}

void copy(memory *mem, char *str, int mbeggin, int mend, int pos, int sbeggin) {
	for (int i = mbeggin, j = sbeggin; i <= mend; i++, j++) {
		mem -> data[pos][i] = str[j];
	}
}

void set_address(list *llist, list *olist, int lcount, int ocount, memory *mem) {
	int flag = 0;
	for (int i = 0; i < ocount; i++) {
		for (int j = 0; j < lcount; j++) {
			if(strcmp(olist[i].label, llist[j].label) == 0) {
				switch(mem -> data[olist[i].address][0]) {
					case '0': {
						if(mem -> data[olist[i].address][1])
							copy(mem, decimal_to_binary(llist[j].address), 11, 31, olist[i].address, 11);
						break;
					}

					case '1': {
						if(mem -> data[olist[i].address][1] == '0')
							copy(mem, decimal_to_binary(llist[j].address), 16, 31, olist[i].address, 16);
						else if (mem -> data[olist[i].address][1] == '1')
							copy(mem, decimal_to_binary(llist[j].address), 6, 31, olist[i].address, 6);
						break;
					}
				}
				break;
			}
			flag = 1;
			break;
		}
		if(flag) {
			yyerror("Inexistent label called by function.");
		}
	}
}
