#include "processor.h"
#include "register.h"
#include "utils.h"
#include <stdio.h>

int EXIT_SIGNAL = 1;

int pc = 0;
int search = 0;
int stall = 1;
int branch = 1;

void fetch(memory *mem, line *li, int *pc, int *ic) {
	int count = 0;
	while (count != search && ic && branch) {
		putIn(mem -> data[mem -> size - *pc - 1], li);
		*ic -= 1;
		*pc += 1;
		count++;
	}
}

void issue(int *pc, line *li, reserve_station *rs, reg_bank *reg) {
	if(!isEmpty(li) && stall) {
		printf("Stalled\n");
		stall = 0;
	} else {
		char *inst = li -> beggin -> data;
		int opp = binary_to_decimal(inst, 0, 5);
		switch(opp) {
			case LD:
			case ST:
			case MOVE:
			case NEG:
			case NOT: {
				int rs_id = empty_rs(rs, opp);
				if(rs_id != EMPTY_RS) {
					set_rs(rs, rs_id, REG_2, inst, opp, reg);
					printf("%d | %d\n", rs_id, opp);
					inst = putOut(li);
				} else
					stall = 0;
				break;
			}
			case ADD:
			case SUB:
			case MULT:
			case DIV:
			case AND:
			case OR:
			case SLL:
			case SLR: {
				int rs_id = empty_rs(rs, opp);
				if(rs_id != EMPTY_RS) {
					set_rs(rs, rs_id, REG_3, inst, opp, reg);
					printf("%d | %d\n", rs_id, opp);
					inst = putOut(li);
				} else
					stall = 0;
				break;
			}
			case LI: {
				int rs_id = empty_rs(rs, opp);
				if(rs_id != EMPTY_RS) {
					set_rs(rs, rs_id, REG_1I, inst, opp, reg);
					printf("%d | %d\n", rs_id, opp);
					inst = putOut(li);
				} else
					stall = 0;
				break;
			}
			case BEQZ:
			case BNEZ:
			case BGTZ:
			case BLEZ: {
				int rs_id = empty_rs(rs, opp);
				if(rs_id != EMPTY_RS) {
					set_rs(rs, rs_id, REG_1L, inst, opp, reg);
					printf("%d | %d\n", rs_id, opp);
					inst = putOut(li);
					branch = 0;
				} else
					stall = 0;
				break;
			}
			case ADDI:
			case SUBI:
			case MULTI:
			case DIVI:
			case ANDI:
			case ORI: {
				int rs_id = empty_rs(rs, opp);
				if(rs_id != EMPTY_RS) {
					printf("%d | %d\n", rs_id, opp);
					set_rs(rs, rs_id, REG_2I, inst, opp, reg);
					inst = putOut(li);
				} else
					stall = 0;
				break;
			}
			case BEQ:
			case BNE:
			case BGT:
			case BGE:
			case BLT:
			case BLE: {
				int rs_id = empty_rs(rs, opp);
				if(rs_id != EMPTY_RS) {
					set_rs(rs, rs_id, REG_2L, inst, opp, reg);
					printf("%d | %d\n", rs_id, opp);
					inst = putOut(li);
					branch = 0;
				} else
					stall = 0;
				break;
			}
			case B: {
				int rs_id = empty_rs(rs, opp);
				if(rs_id != EMPTY_RS) {
					set_rs(rs, rs_id, REG_2L, inst, opp, reg);
					printf("%d | %d\n", rs_id, opp);
					inst = putOut(li);
					branch = 0;
				} else
					stall = 0;
				break;
			}
		}
	}
}

void execute(int *pc, reserve_station *rs) {
	for(int i = 0; i < rs_total; i++) {
		if(rs[i].busy != EMPTY_RS) {
			int busy = rs[i].id;
			if(rs[busy].qj == EMPTY_RS || rs[busy].qk == EMPTY_RS)
				printf("cebola\n");
				//cdb(pc, rs);
		} else {
			continue;
		}
	}
}

void cdb(int *pc, reserve_station *rs) {
}
