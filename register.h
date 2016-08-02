#ifndef REGISTER_H_
#define REGISTER_H_

typedef struct reg {
	int flag;
	char reg[32];
} reg;

char *get_register(char *str);

#endif
