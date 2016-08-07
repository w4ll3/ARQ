#ifndef REGISTER_H_
#define REGISTER_H_

#define AVAILABLE -1
#define REG_TOTAL 32
#define BUSY -2

typedef struct {
	int qi;
	char *data;
} reg_bank;

reg_bank *initiate_breg();

int available_reg(reg_bank *reg);

void print_reg(reg_bank *reg);

#endif
