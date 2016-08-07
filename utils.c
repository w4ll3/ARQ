#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "utils.h"

char *get_register(char *str) {
	char *aux = (char*) malloc(3);
	int i = 1;
	while(str[i] != '\0') {
		aux[i - 1] = str[i];
		i++;
	}
	aux[i] = '\0';
	return aux;
}

void print_minus(int quantity) {
	while (quantity != 0) {
		printf("%c", '-');
		quantity--;
	}
}

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

int binary_to_decimal(char *str, int beggin, int end) {
	int result = 0;
	for(int i = end; i >= beggin; i--) {
		if(str[i] == '1')
			result += pow(2, end - i);
	}
	return result;
}
