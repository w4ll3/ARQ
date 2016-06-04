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

void checkOp(FILE *entry, char *buffer) {
	while (!feof(entry)) {
		fgets(buffer, 256, entry);
		switch (buffer[0]) {
			case 'a': {
				if(buffer[1] == 'd') {
					if(buffer[2] == 'd') {
						if(buffer[3] == 'i') {
							//ADDI
						} else {
							if(buffer[3] == ' ') {
								//ADD
							}
						}
					}
				} else {
					if(buffer[1] == 'n') {
						if(buffer[2] == 'd') {
								//AND
							} else {
								if(buffer[3] == 'i') {
									//ADDI
								}
							}
					}
				}
			} break;

			case 'b': {
				if(buffer[1] == ' ') {
						//B
						printf("%s\n", "b");
				}
				if(buffer[1] == 'e') {
					if(buffer[2] == 'q') {
						if(buffer[3] == 'z') {
							if(buffer[4] == ' '){
								//BEQZ
								printf("%s\n", "beqz");
							}
						} else {
							if(buffer[3] == ' ') {
								//BEQ
								printf("%s\n", "beq");
							}
						}
					}
				}
				if(buffer[1] == 'g') {
					if(buffer[2] == 't') {
						if(buffer[3] == 'z') {
							if(buffer[4] == ' ') {
								//BGTZ
								printf("%s\n", "bgtz");
							}
						} else {
							if(buffer[3] == ' ') {
								//BGT
								printf("%s\n", "bgt");
							} else {
								if(buffer[2] == 'e') {
									if(buffer[3] == ' ') {
										//BGE
										printf("%s\n", "bge");
									}
								}
							}
						}
					}
				}
				if(buffer[1] == 'l') {
					if(buffer[2] == 't') {
						if(buffer[3] == ' ') {
							//BLT
							printf("%s\n", "blt");
						}
					} else {
						if(buffer[2] == 'e') {
							if(buffer[3] == 'z') {
								if(buffer[4] == ' ') {
									//BLEZ
									printf("%s\n", "blez");
								} else {
									if(buffer[3] == ' ') {
										//BLE
										printf("%s\n", "ble");
									}
								}
							}
						}
					}
				}
				if(buffer[1] == 'n') {
					if(buffer[2] == 'e') {
						if(buffer[3] == 'z') {
							if(buffer[4] == ' ') {
								//BNEZ
								printf("%s\n", "bnez");
							}
						} else {
							if(buffer[3] == ' ') {
								//BNE
								printf("%s\n", "bne");
							}
						}
					}
				}
			} break;

			case 'd': {
				if(buffer[1] == 'i') {
					if(buffer[2] == 'v') {
						if(buffer[3] == ' ') {
							//DIVI
							printf("%s\n", "divi");
						} else {
							if(buffer[3] == ' ') {
								//DIV
								printf("%s\n", "div");
							}
						}
					}
				}
			} break;

			case 'l': {
				if(buffer[1] == 'd') {
					if(buffer[2] == ' ') {
							//LD
							printf("%s\n", "ld");
					}
				} else {
					if(buffer[1] == 'i') {
						if(buffer[2] == ' ') {
							//LI
							printf("%s\n", "li");
						}
					}
				}
			} break;

			case 'm': {
				if(buffer[1] == 'o') {
					if(buffer[2] == 'v') {
						if(buffer[3] == 'e') {
							if(buffer[4] == ' ') {
								//MOVE
								printf("%s\n", "move");
							}
						}
					}
				} else {
					if(buffer[1] == 'u') {
						if(buffer[2] == 'l') {
							if(buffer[3] == 't') {
								if(buffer[4] == 'i') {
									if(buffer[5] == ' ') {
										//ADDI
										printf("%s\n", "addi");
									}
							} else {
									if(buffer[4] == ' ') {
										//ADD
										printf("%s\n", "add");
									}
								}
							}
						}
					}
				}
			} break;

			case 'n': {
				if(buffer[1] == 'e') {
					if(buffer[2] == 'g') {
						if(buffer[3] == ' ') {
							//NEG
							printf("%s\n", "neg");
						}
					}
				} else {
					if(buffer[1] == 'o') {
						if(buffer[2] == 't') {
							if(buffer[3] == ' ') {
								//NOT
								printf("%s\n", "not");
							}
						}
					}
				}
			} break;

			case 'o': {
				if(buffer[1] == 'r') {
					if(buffer[2] == 'i') {
						if(buffer[3] == ' ') {
							//ORI
							printf("%s\n", "ori");
						}
					}
				} else {
					if(buffer[1] == ' ') {
						//OR
						printf("%s\n", "or");
					}
				}
			} break;

			case 's': {
				if(buffer[1] == 'l') {
					if(buffer[2] == 'l') {
						if(buffer[3] == ' ') {
							//SLL
							printf("%s\n", "sll");
						}
					} else {
						if(buffer[1] == 'r') {
							if(buffer[2] == ' ') {
								//SLR
								printf("%s\n", "slr");
							}
						}
					}
				} else {
					if(buffer[1] == 't') {
						if(buffer[2] == ' ') {
							//ST
							printf("st");
						}
					}
				}
				if(buffer[1] == 'u') {
					if(buffer[2] == 'b') {
						if(buffer[3] == 'i') {
							if(buffer[4] == ' ') {
								//SUBI
								printf("subi");
							}
						} else {
							if(buffer[3] == ' ') {
								//SUB
								printf("sub");
							}
						}
					}
				}
			} break;

			default: {
				printf("Invalid instruction set. Aborting.");
			} break;
		}
	}
}

/*Set the architecture parameters*/
void arch_parametrize(FILE *entry) {
	char buffer[256] = NULL;
	fgets(buffer, 256, entry);
	if (strcmp(buffer, "ARQUITETURA\n") != 0) {
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
void opcode_parametrize(FILE *entry) {
	char buffer[256] = NULL;
	fgets(buffer, 256, entry);
	if (strcmp(buffer, "CICLOS") != 0) {
		printf("Invalid format of entry\n");
		exit(-1);
	}
}

int main(int argc, char *argv[]) {
	FILE *entry;
	entry = fopen(argv[1], "r");
	if (entry == NULL) {
		printf("Invalid filename, aborting...");
		return 0;
	}
	arch_parametrize(entry);
	printf("\nBye Bye.");
	return 0;
}
