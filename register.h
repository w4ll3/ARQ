#ifndef REGISTER_H_
#define REGISTER_H_

typedef struct {
	int flag, qi;
	char reg[32];
} reg;

char *get_register(char *str);

#endif
