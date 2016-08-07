#include "register.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

reg_bank *initiate_breg() {
	reg_bank *reg = (reg_bank*) malloc(sizeof(reg_bank) * REG_TOTAL);
	for(int i = 0; i < REG_TOTAL; i++) {
		reg[i].qi = AVAILABLE;
		reg[i].data = decimal_to_binary(50);
	}
	return reg;
}

int available_reg(reg_bank *reg) {
	for(int i = 0; i < REG_TOTAL; i++) {
		if(reg[i].qi == AVAILABLE)
			return i;
	}
	return BUSY;
}

void print_reg(reg_bank *reg) {
	printf(".");
	print_minus(80);
	printf(".\n");
	for (int i = 0; i < REG_TOTAL; i++) {
		printf("|[%.2d]\t\t", i);
		for (int j = 0; j < 32; j++) {
			if(reg[i].data[j] == '\0') {
				printf("%2c", ' ');
			} else {
				printf("%2c", reg[i].data[j]);
			}
		}
		printf(" |\n");
	}
	printf("*");
	print_minus(80);
	printf("*\n");
}
