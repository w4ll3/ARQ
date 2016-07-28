#include "memory.h"

memory *initialize_mem(int size) {
	memory *mem = (memory*) malloc(sizeof(memory));
	mem -> data = (char**) malloc(size * sizeof(memory));
	for (int i = 0; i < size; i++) {
		mem -> data[i] = (char*) calloc(32, sizeof(char));
	}
	mem -> size = size;
	return mem;
}

void set_opcode(char *opcode, memory *mem, int pos) {
	for (size_t i = 0; i < MEMSIZE; i++) {
		mem -> data[pos][i] = opcode[i];
	}
}

void print_mem(memory mem) {
}

void set_format1(register *reg1, register *reg2, register *reg3) {

}
