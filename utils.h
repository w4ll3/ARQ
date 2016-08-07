#ifndef UTILS_H_
#define UTILS_H_

#define EMPTY_POS "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"

typedef struct list {
	char *label;
	int address;
} list;

char *get_register(char *str);

void print_minus(int quantity);

list *initialize_list();

void insert_list(list *ilist, char *label, int address, int *size);

void show_list(list *ilist, int size);

char *decimal_to_binary(int n);

int binary_to_decimal(char *str, int beggin, int end);

#endif
