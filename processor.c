#include "processor.h"
#include "register.h"
#include "utils.h"

int EXIT_SIGNAL = 1;

int pc = 0;
int search = 0;
int stall = 1;

void fetch(memory *mem, line *li, int *pc) {
	int count = 0;
	while (count != search) {
		putIn(mem -> data[mem -> size - *pc - 1], li);
		printf("| %d | %s\n", *pc, mem -> data [mem -> size - *pc - 1]);
		*pc += 1;
		count++;
	}
}

void issue(int *pc, line *li) {
	if(!isEmpty(li) && stall) {
		printf("Stalled\n");
		stall = 0;
	} else {
		char *inst = putOut(li);
		int opp = binary_to_decimal(inst, 0, 6);
		switch(opp) {
			case LD: {
				break;
			}
			case ST: {
				break;
			}
			case MOVE: {
				break;
			}
			case NEG: {
				break;
			}
			case NOT: {
				break;
			}
			case ADD: {
				break;
			}
			case SUB: {
				break;
			}
			case MULT: {
				break;
			}
			case DIV: {
				break;
			}
			case AND: {
				break;
			}
			case OR: {
				break;
			}
			case SLL: {
				break;
			}
			case SLR: {
				break;
			}
			case LI: {
				break;
			}
			case BEQZ: {
				break;
			}
			case BNEZ: {
				break;
			}
			case BGTZ: {
				break;
			}
			case BLEZ: {
				break;
			}
			case ADDI: {
				break;
			}
			case SUBI: {
				break;
			}
			case MULTI: {
				break;
			}
			case DIVI: {
				break;
			}
			case ANDI: {
				break;
			}
			case ORI: {
				break;
			}
			case BEQ: {
				break;
			}
			case BNE: {
				break;
			}
			case BGT: {
				break;
			}
			case BGE: {
				break;
			}
			case BLT: {
				break;
			}
			case BLE: {
				break;
			}
		}
	}
}

void execute(int *pc) {

}
