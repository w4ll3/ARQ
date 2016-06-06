#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 64

/*Gets the opcode of the operation in the buffer*/
int get_opcode(char buffer[]) {
	if(strcmp(buffer, "add") == 0) {
		return 000101;
	}
	if(strcmp(buffer, "addi") == 0) {
		return 100000;
	}
	if(strcmp(buffer, "and") == 0) {
		return 001001;
	}
	if(strcmp(buffer, "andi") == 0) {
		return 100100;
	}
	if(strcmp(buffer, "b") == 0) {
		return 110000;
	}
	if(strcmp(buffer, "beq") == 0) {
		return 100110;
	}
	if(strcmp(buffer, "beqz") == 0) {
		return 010001;
	}
	if(strcmp(buffer, "bgt") == 0) {
		return 101001;
	}
	if(strcmp(buffer, "bge") == 0) {
		return 101000;
	}
	if(strcmp(buffer, "bgtz") == 0) {
		return 010011;
	}
	if(strcmp(buffer, "blt") == 0) {
		return 101011;
	}
	if(strcmp(buffer, "ble") == 0) {
		return 010100;
	}
	if(strcmp(buffer, "blez") == 0) {
		return 101010;
	}
	if(strcmp(buffer, "bne") == 0) {
		return 100111;
	}
	if(strcmp(buffer, "bnez") == 0) {
		return 010010;
	}
	if(strcmp(buffer, "div") == 0) {
		return 001000;
	}
	if(strcmp(buffer, "divi") == 0) {
		return 100011;
	}
	if(strcmp(buffer, "ld") == 0) {
		return 000000;
	}
	if(strcmp(buffer, "li") == 0) {
		return 010000;
	}
	if(strcmp(buffer, "move") == 0) {
		return 000010;
	}
	if(strcmp(buffer, "mult") == 0) {
		return 000111;
	}
	if(strcmp(buffer, "multi") == 0) {
		return 100010;
	}
	if(strcmp(buffer, "neg") == 0) {
		return 000011;
	}
	if(strcmp(buffer, "not") == 0) {
		return 000100;
	}
	if(strcmp(buffer, "or") == 0) {
		return 001010;
	}
	if(strcmp(buffer, "ori") == 0) {
		return 100101;
	}
	if(strcmp(buffer, "sll") == 0) {
		return 001011;
	}
	if(strcmp(buffer, "slr") == 0) {
		return 001100;
	}
	if(strcmp(buffer, "st") == 0) {
		return 000001;
	}
	if(strcmp(buffer, "sub") == 0) {
		return 000110;
	}
	if(strcmp(buffer, "subi") == 0) {
		return 100001;
	}
	return -1;
}

/*Function that fills the buffer with '\0'*/
void clear_buffer(char *buffer) {
	for(int i = 0; i < SIZE; i++) {
		buffer[i] = '\0';
	}
}

/*Remove '\t', ' ', '\n' from strings*/
void remove_spaces(char *buffer) {
	int i = 0, cont = 0, j = 0;
	for(j = 0; i < strlen(buffer); j++, i++) {
		while(buffer[i] == ' ' || buffer[i] == '\t' || buffer[i] == '\n') {
			i++;
			cont++;
		}
		buffer[j] = buffer[i];
	}
	while(cont >= 0) {
		buffer[j + cont] = '\0';
		cont--;
	}
}

/*Function to get the parameters and transform them to int*/
int get_parameter(char *buf) {
	char *aux = strtok(buf, "=");
	int output = atoi(strtok(NULL, "="));
	strncpy(buf, aux, SIZE);
	return output;
}

/*Function that gets line, remove spaces and returns the formated line*/
char *get_line(FILE *entry, char *buffer) {
	fgets(buffer, SIZE, entry);
	remove_spaces(buffer);
	return buffer;
}

/*Function that generates the binary file*/
void gen_binary(FILE *entry, char *buffer, int *line) {
	*line += 1;
	if(!strcmp(get_line(entry, buffer), ".data")) {
		printf("'%s' in line %d is not a valid instruction directive. Aborting...", buffer, *line);
		exit(-1);
	} else {
		while(!feof(entry)) {
			*line += 1;
			if(strlen(get_line(entry, buffer)) > 1) printf("%d | %s\n", *line, buffer);
		}
	}
	printf("Binary conversion successfully executed.\n\nInitiating now the program.\n");
}

/*Set operations clock duration*/
void clk_parametrize(FILE *entry, char *buffer, int *line) {
	*line += 1;
	int settled[31] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	if(strcmp(buffer, "CICLOS") != 0) {
		printf("'%s' in line %d is not a valid instruction directive. Aborting...", buffer, *line);
		exit(-1);
	} else {
		while(strcmp(get_line(entry, buffer), "TEXTO") != 0) {
			*line += 1;
			if(!strcmp(buffer, "\0")) continue;
			int value = get_parameter(buffer);
			printf("%d | %d | %s\n", *line, value, buffer);
			switch(get_opcode(buffer)) {
				case 000000: {
					settled[0] = 1;
					break;
				}
				case 000001: {
					if(settled[1] == 0) {
						settled[1] = 1;
					} else {
						printf("Duplicated occurrence of '%s' in line %d. Aborting...", buffer, *line);
						exit(-1);
					}
					break;
				}
				case 000010: {
					if(settled[2] == 0) {
						settled[2] = 1;
					} else {
						printf("Duplicated occurrence of '%s' in line %d. Aborting...", buffer, *line);
						exit(-1);
					}
					break;
				}
				case 000011: {
					if(settled[3] == 0) {
						settled[3] = 1;
					} else {
						printf("Duplicated occurrence of '%s' in line %d. Aborting...", buffer, *line);
						exit(-1);
					}
					break;
				}
				case 000100: {
					if(settled[4] == 0) {
						settled[4] = 1;
					} else {
						printf("Duplicated occurrence of '%s' in line %d. Aborting...", buffer, *line);
						exit(-1);
					}
					break;
				}
				case 000101: {
					if(settled[5] == 0) {
						settled[5] = 1;
					} else {
						printf("Duplicated occurrence of '%s' in line %d. Aborting...", buffer, *line);
						exit(-1);
					}
					break;
				}
				case 000110: {
					if(settled[6] == 0) {
						settled[6] = 1;
					} else {
						printf("Duplicated occurrence of '%s' in line %d. Aborting...", buffer, *line);
						exit(-1);
					}
					break;
				}
				case 000111: {
					if(settled[7] == 0) {
						settled[7] = 1;
					} else {
						printf("Duplicated occurrence of '%s' in line %d. Aborting...", buffer, *line);
						exit(-1);
					}
					break;
				}
				case 001000: {
					if(settled[8] == 0) {
						settled[8] = 1;
					} else {
						printf("Duplicated occurrence of '%s' in line %d. Aborting...", buffer, *line);
						exit(-1);
					}
					break;
				}
				case 001001: {
					if(settled[9] == 0) {
						settled[9] = 1;
					} else {
						printf("Duplicated occurrence of '%s' in line %d. Aborting...", buffer, *line);
						exit(-1);
					}
					break;
				}
				case 001010: {
					if(settled[10] == 0) {
						settled[10] = 1;
					} else {
						printf("Duplicated occurrence of '%s' in line %d. Aborting...", buffer, *line);
						exit(-1);
					}
					break;
				}
				case 001011: {
					if(settled[11] == 0) {
						settled[11] = 1;
					} else {
						printf("Duplicated occurrence of '%s' in line %d. Aborting...", buffer, *line);
						exit(-1);
					}
					break;
				}
				case 001100: {
					if(settled[12] == 0) {
						settled[12] = 1;
					} else {
						printf("Duplicated occurrence of '%s' in line %d. Aborting...", buffer, *line);
						exit(-1);
					}
					break;
				}
				case 010000: {
					if(settled[13] == 0) {
						settled[13] = 1;
					} else {
						printf("Duplicated occurrence of '%s' in line %d. Aborting...", buffer, *line);
						exit(-1);
					}
					break;
				}
				case 010001: {
					if(settled[14] == 0) {
						settled[14] = 1;
					} else {
						printf("Duplicated occurrence of '%s' in line %d. Aborting...", buffer, *line);
						exit(-1);
					}
					break;
				}
				case 010010: {
					if(settled[15] == 0) {
						settled[15] = 1;
					} else {
						printf("Duplicated occurrence of '%s' in line %d. Aborting...", buffer, *line);
						exit(-1);
					}
					break;
				}
				case 010011: {
					if(settled[16] == 0) {
						settled[16] = 1;
					} else {
						printf("Duplicated occurrence of '%s' in line %d. Aborting...", buffer, *line);
						exit(-1);
					}
					break;
				}
				case 010100: {
					if(settled[17] == 0) {
						settled[17] = 1;
					} else {
						printf("Duplicated occurrence of '%s' in line %d. Aborting...", buffer, *line);
						exit(-1);
					}
					break;
				}
				case 100000: {
					if(settled[18] == 0) {
						settled[18] = 1;
					} else {
						printf("Duplicated occurrence of '%s' in line %d. Aborting...", buffer, *line);
						exit(-1);
					}
					break;
				}
				case 100001: {
					if(settled[19] == 0) {
						settled[19] = 1;
					} else {
						printf("Duplicated occurrence of '%s' in line %d. Aborting...", buffer, *line);
						exit(-1);
					}
					break;
				}
				case 100011: {
					if(settled[20] == 0) {
						settled[20] = 1;
					} else {
						printf("Duplicated occurrence of '%s' in line %d. Aborting...", buffer, *line);
						exit(-1);
					}
					break;
				}
				case 100010: {
					if(settled[21] == 0) {
						settled[21] = 1;
					} else {
						printf("Duplicated occurrence of '%s' in line %d. Aborting...", buffer, *line);
						exit(-1);
					}
					break;
				}
				case 100100: {
					if(settled[22] == 0) {
						settled[22] = 1;
					} else {
						printf("Duplicated occurrence of '%s' in line %d. Aborting...", buffer, *line);
						exit(-1);
					}
					break;
				}
				case 100101: {
					if(settled[23] == 0) {
						settled[23] = 1;
					} else {
						printf("Duplicated occurrence of '%s' in line %d. Aborting...", buffer, *line);
						exit(-1);
					}
					break;
				}
				case 100110: {
					if(settled[24] == 0) {
						settled[24] = 1;
					} else {
						printf("Duplicated occurrence of '%s' in line %d. Aborting...", buffer, *line);
						exit(-1);
					}
					break;
				}
				case 100111: {
					if(settled[25] == 0) {
						settled[25] = 1;
					} else {
						printf("Duplicated occurrence of '%s' in line %d. Aborting...", buffer, *line);
						exit(-1);
					}
					break;
				}
				case 101000: {
					if(settled[26] == 0) {
						settled[26] = 1;
					} else {
						printf("Duplicated occurrence of '%s' in line %d. Aborting...", buffer, *line);
						exit(-1);
					}
					break;
				}
				case 101001: {
					if(settled[27] == 0) {
						settled[27] = 1;
					} else {
						printf("Duplicated occurrence of '%s' in line %d. Aborting...", buffer, *line);
						exit(-1);
					}
					break;
				}
				case 101010: {
					if(settled[28] == 0) {
						settled[28] = 1;
					} else {
						printf("Duplicated occurrence of '%s' in line %d. Aborting...", buffer, *line);
						exit(-1);
					}
					break;
				}
				case 101011: {
					if(settled[29] == 0) {
						settled[29] = 1;
					} else {
						printf("Duplicated occurrence of '%s' in line %d. Aborting...", buffer, *line);
						exit(-1);
					}
					break;
				}
				case 110000: {
					if(settled[30] == 0) {
						settled[30] = 1;
					} else {
						printf("Duplicated occurrence of '%s' in line %d. Aborting...", buffer, *line);
						exit(-1);
					}
					break;
				}
				default: {
					printf("'%s' in line %d is not a valid operation. Aborting...", buffer, *line);
					exit(-1);
				}
			}
		}
	}
	printf("Clocks successfully settled. \n\nInitiating binary conversion.\n");
	gen_binary(entry, buffer, line);
}

/*Set the architecture parameters*/
void arch_parametrize(FILE *entry, int *line) {
	int sum_ver = 0, mul_ver = 0, div_ver = 0, bi_ver = 0, bc_ver = 0, be_ver = 0;
	char buffer[SIZE];
	clear_buffer(buffer);
	*line += 1;
	if(strcmp(get_line(entry, buffer), "ARQUITETURA")) {
		printf("Error in line %d. Invalid format of entry\n", *line);
		exit(-1);
	} else {
		while(strcmp(get_line(entry, buffer), "CICLOS")) {
			*line += 1;
			if(!strcmp(buffer, "\0")) continue;
			int value = get_parameter(buffer);
			if(!strcmp(buffer, "somador")) {
				if(sum_ver == 0) {
					printf("%d | %5d | %s\n", *line, value, buffer);
					/*TODO: set_sum(value)*/
					sum_ver = 1;
					clear_buffer(buffer);
				} else {
					printf("Duplicated occurrence of '%s' in line %d. Aborting...\n", buffer, line);
					exit(-1);
				}
			} else {
				if(!strcmp(buffer, "multiplicador")) {
					if(mul_ver == 0) {
						printf("%d | %5d | %s\n", *line, value, buffer);
						/*TODO: set_mul(value)*/
						mul_ver = 1;
						clear_buffer(buffer);
					} else {
						printf("Duplicated occurrence of '%s' in line %d. Aborting...\n", buffer, line);
						exit(-1);
					}
				} else {
					if(!strcmp(buffer, "divisor")) {
						if(div_ver == 0) {
							printf("%d | %5d | %s\n", *line, value, buffer);
							/*TODO: set_div(value)*/
							div_ver = 1;
							clear_buffer(buffer);
						} else {
							printf("Duplicated occurrence of '%s' in line %d. Aborting...\n", buffer, line);
							exit(-1);
						}
					} else {
						if(!strcmp(buffer, "busca_de_instrucoes")) {
							if(bi_ver == 0) {
								printf("%d | %5d | %s\n", *line, value, buffer);
								/*TODO: set_search(value)*/
								bi_ver = 1;
								clear_buffer(buffer);
							} else {
								printf("Duplicated occurrence of '%s' in line %d. Aborting...\n", buffer, line);
								exit(-1);
							}
						} else {
							if(!strcmp(buffer, "buffer_de_carga")) {
								if(bc_ver == 0) {
									printf("%d | %5d | %s\n", *line, value, buffer);
									/*TODO: set_charge(value)*/
									bc_ver = 1;
									clear_buffer(buffer);
								} else {
									printf("Duplicated occurrence of '%s' in line %d. Aborting...\n", buffer, line);
									exit(-1);
								}
							} else {
								if(!strcmp(buffer, "buffer_de_escrita")) {
									if(be_ver == 0) {
										printf("%d | %5d | %s\n", *line, value, buffer);
										/*TODO: set_write(value)*/
										be_ver = 1;
										clear_buffer(buffer);
									} else {
										printf("Duplicated occurrence of '%s' in line %d. Aborting...\n", buffer, line);
										exit(-1);
									}
								} else {
									printf("'%s' in line %d is not a valid operation. Aborting...", buffer, *line);
									exit(-1);
								}
							}
						}
					}
				}
			}
		}
		printf("Architecture successfully loaded.\n\nStarting to read operations clock duration.\n");
		clk_parametrize(entry, buffer, line);
	}
}

int main(int argc, char *argv[]) {
	int line = 0;
	FILE *entry;
	entry = fopen(argv[1], "r");
	if(entry == NULL) {
		printf("Invalid filename, aborting...");
		return 0;
	}
	printf("\nStarting to set the architecture parameters.\n");
	arch_parametrize(entry, &line);
	printf("\nBye Bye.");
	return 0;
}
