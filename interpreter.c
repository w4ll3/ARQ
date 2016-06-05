#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 64

void remove_spaces(char *buffer) {
	int i = 0;
	while(buffer[0] == ' ' || buffer[i] == '\t') i++;
	for(int j = 0; buffer[i] != '\0'; j++, i++)
		buffer[j] = buffer[i];
}

/*Function that fills the buffer with '\0'*/
void clear_buffer(char *buffer) {
	for(int i = 0; i < SIZE; i++) {
		buffer[i] = '\0';
	}
}

/*Function to get the parameters and transform them to int*/
int get_parameter(char *buf) {
	remove_spaces(buf);
	char *aux = strtok(buf, " =");
	int output = atoi(strtok(NULL, " ="));
	strncpy(buf, aux, SIZE);
	return output;
}

/*Set operations clock duration*/
void clk_parametrize(FILE *entry, char *buffer) {
	if(strcmp(buffer, "CICLOS\n") != 0) {
		printf("Invalid entry file.");
		exit(-1);
	} else {
		while(strcmp(fgets(buffer, SIZE, entry), "TEXTO\n")) {
			if(!strcmp(buffer, "\n")) continue;
			int value = get_parameter(buffer);
			printf("%d | %s\n", value, buffer);
			if(strcmp(buffer, "add") == 0) {
				/*TODO:ADD*/
			}
			if(strcmp(buffer, "addi") == 0) {
				/*TODO:ADDI*/
			}
			if(strcmp(buffer, "and") == 0) {
				/*TODO:AND*/
			}
			if(strcmp(buffer, "andi") == 0) {
				/*TODO:ANDI*/
			}
			if(strcmp(buffer, "b") == 0) {
				/*TODO:B*/
			}
			if(strcmp(buffer, "beq") == 0) {
				/*TODO:BEQ*/
			}
			if(strcmp(buffer, "beqz") == 0) {
				/*TODO:BEQZ*/
			}
			if(strcmp(buffer, "bgt") == 0) {
				/*TODO:BGT*/
			}
			if(strcmp(buffer, "bge") == 0) {
				/*TODO:BGE*/
			}
			if(strcmp(buffer, "bgtz") == 0) {
				/*TODO:BGTZ*/
			}
			if(strcmp(buffer, "blt") == 0) {
				/*TODO:BLT*/
			}
			if(strcmp(buffer, "ble") == 0) {
				/*TODO:BLE*/
			}
			if(strcmp(buffer, "blez") == 0) {
				/*TODO:BLEZ*/
			}
			if(strcmp(buffer, "bne") == 0) {
				/*TODO:BNE*/
			}
			if(strcmp(buffer, "bnez") == 0) {
				/*TODO:BNEZ*/
			}
			if(strcmp(buffer, "div") == 0) {
				/*TODO:DIV*/
			}
			if(strcmp(buffer, "divi") == 0) {
				/*TODO:DIVI*/
			}
			if(strcmp(buffer, "ld") == 0) {
				/*TODO:LD*/
			}
			if(strcmp(buffer, "li") == 0) {
				/*TODO:LI*/
			}
			if(strcmp(buffer, "move") == 0) {
				/*TODO:MOVE*/
			}
			if(strcmp(buffer, "mult") == 0) {
				/*TODO:MULT*/
			}
			if(strcmp(buffer, "multi") == 0) {
				/*TODO:MULTI*/
			}
			if(strcmp(buffer, "neg") == 0) {
				/*TODO:NEG*/
			}
			if(strcmp(buffer, "not") == 0) {
				/*TODO:NOT*/
			}
			if(strcmp(buffer, "or") == 0) {
				/*TODO:ADDI*/
			}
			if(strcmp(buffer, "ori") == 0) {
				/*TODO:ORI*/
			}
			if(strcmp(buffer, "sll") == 0) {
				/*TODO:SLL*/
			}
			if(strcmp(buffer, "slr") == 0) {
				/*TODO:SLR*/
			}
			if(strcmp(buffer, "st") == 0) {
				/*TODO:ST*/
			}
			if(strcmp(buffer, "sub") == 0) {
				/*TODO:SUB*/
			}
			if(strcmp(buffer, "subl") == 0) {
				/*TODO:SUBL*/
			}
		}
	}
}

/*Set the architecture parameters*/
void arch_parametrize(FILE *entry) {
	int sum_ver = 0, mul_ver = 0, div_ver = 0, bi_ver = 0, bc_ver = 0, be_ver = 0;
	char buffer[SIZE];
	clear_buffer(buffer);
	if(strcmp(fgets(buffer, SIZE, entry), "ARQUITETURA\n")) {
		printf("Invalid format of entry\n");
		exit(-1);
	} else {
		while(strcmp(fgets(buffer, SIZE, entry), "CICLOS\n")) {
			if(!strcmp(buffer, "\n")) continue;
			int value = get_parameter(buffer);
			if(!strcmp(buffer, "somador")) {
				if(sum_ver == 0) {
					printf("%d | %s\n", value, buffer);
					/*TODO: set_sum(value)*/
					sum_ver = 1;
					clear_buffer(buffer);
				} else {
					printf("Existem ocorrencias duplicadas de somador na parametrizacao da arquitetura.\n");
					exit(-1);
				}
			}
			if(!strcmp(buffer, "multiplicador")) {
				if(mul_ver == 0) {
					printf("%d | %s\n", value, buffer);
					/*TODO: set_mul(value)*/
					mul_ver = 1;
					clear_buffer(buffer);
				} else {
					printf("Existem ocorrencias duplicadas de multiplicador na parametrizacao da arquitetura.\n");
					exit(-1);
				}
			}
			if(!strcmp(buffer, "divisor")) {
				if(div_ver == 0) {
					printf("%d | %s\n", value, buffer);
					/*TODO: set_div(value)*/
					div_ver = 1;
					clear_buffer(buffer);
				} else {
					printf("Existem ocorrencias duplicadas de divisor na parametrizacao da arquitetura.\n");
					exit(-1);
				}
			}
			if(!strcmp(buffer, "busca_de_instrucoes")) {
				if(bi_ver == 0) {
					printf("%d | %s\n", value, buffer);
					/*TODO: set_search(value)*/
					bi_ver = 1;
					clear_buffer(buffer);
				} else {
					printf("Existem ocorrencias duplicadas de busca de instrucoes na parametrizacao da arquitetura.\n");
					exit(-1);
				}
			}
			if(!strcmp(buffer, "buffer_de_carga")) {
				if(bc_ver == 0) {
					printf("%d | %s\n", value, buffer);
					/*TODO: set_charge(value)*/
					bc_ver = 1;
					clear_buffer(buffer);
				} else {
					printf("Existem ocorrencias duplicadas de buffer de carga na parametrizacao da arquitetura.\n");
					exit(-1);
				}
			}
			if(!strcmp(buffer, "buffer_de_escrita")) {
				if(be_ver == 0) {
					printf("%d | %s\n", value, buffer);
					/*TODO: set_write(value)*/
					be_ver = 1;
					clear_buffer(buffer);
				} else {
					printf("Existem ocorrencias duplicadas de buffer de escrita na parametrizacao da arquitetura.\n");
					exit(-1);
				}
			}
		}
		clk_parametrize(entry, buffer);
	}
}

int main(int argc, char *argv[]) {
	FILE *entry;
	entry = fopen(argv[1], "r");
	if(entry == NULL) {
		printf("Invalid filename, aborting...");
		return 0;
	}
	arch_parametrize(entry);
	printf("\nBye Bye.");
	return 0;
}
