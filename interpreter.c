#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//TODO: include "CPU.h"

/*Function to get the parameters and transform them to int*/
int get_parameter(char buf[]) {
	printf("%s\n", strtok(buf, "= "));
	int output = atoi(strtok(NULL, "= "));	
	return output;
}

/*Set the architecture parameters*/
void arch_parametrize(FILE *entry, char *buffer) {
	if(strcmp(buffer, "ARQUITETURA\n") != 0) {
		printf("Invalid format of entry\n");
		exit(-1);
	}
	/*TODO:
	fgets(buffer, 256, entry);
	set_sum(get_parameter(buffer));
	fgets(buffer, 256, entry);
	set_mult(get_parameter(buffer));
	fgets(buffer, 256, entry);
	set_div(get_parameter(buffer));
	fgets(buffer, 256, entry);
	set_opsearch(get_parameter(buffer));
	fgets(buffer, 256, entry);
	set_charge(get_parameter(buffer));
	fgets(buffer, 256, entry);
	buffer_write(get_parameter(buffer));
	*/
}

/*Set the clock times for each operation*/
void opcode_parametrize(FILE *entry, char *buffer) {
	if(strcmp(buffer, "CICLOS") != 0) {
		printf("Invalid format of entry\n");
		exit(-1);
	}
	
}

int main(int argc, char *argv[]) {
	char buffer[256];
	FILE *entry;
	entry = fopen(argv[1], "r");
	if(entry == NULL) {
		printf("Invalid filename, aborting...");
		return 0;
	}
	fgets(buffer, 256, entry);
	arch_parametrize(entry, buffer);
	printf("Bye Bye.");
	return 0;
}
