#include "memory.h"

void left_shift(memory *mem) {

}

void right_shift(memory *mem) {

}

void initialize_mem(memory *mem) {
	mem -> data = (char**) malloc(MEMSIZE * sizeof(char));
	for (int i = 0; i < MEMSIZE; i++) {
		mem -> data[i] = (char*) calloc(32, sizeof(char));
	}
	mem -> size = MEMSIZE;
}

void set_opcode(char *opcode, memory *mem, int pos) {
	strcat(mem -> data[pos], opcode);
	printf("%s\n", mem -> data[pos]);
}
