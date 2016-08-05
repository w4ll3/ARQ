#include "register.h"
#include <stdio.h>
#include <stdlib.h>

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
