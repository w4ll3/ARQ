#include "functional_unit.h"
#include "rs.h"
#include <stdio.h>
#include <stdlib.h>

int cicles[48];

int fu_sum, fu_div, fu_mult, fu_total;

fu_unit *initiate_fu(int sum, int div, int mult) {
	fu_sum = sum;
	fu_div = div;
	fu_mult = mult;
	fu_total = sum + div + mult;
	fu_unit *fu = (fu_unit*) malloc(sizeof(fu_unit) * fu_total);
	for(int i = 0; i < fu_total; i++) {
		fu[i].id = i;
		fu[i].cicles = 0;
		fu[i].rs = NONE;
	}
	return fu;
}

int find_fu(int id, fu_unit *fu) {
	for(int i = 0; i < fu_total; i++) {
		if(fu[i].rs == id)
			return i;
	}
	return NOT_RUNNING;
}

int empty_fu(fu_unit *fu, int opp) {
	switch(opp) {
		case 7:
		case 34: {
			for(int i = fu_sum; i < fu_div; i++) {
				if(fu[i].rs == NONE)
					return i;
			}
			break;
		}
		case 8:
		case 35: {
			for(int i = fu_div; i < fu_mult; i++) {
				if(fu[i].rs == NONE)
					return i;
			}
			break;
		}
		default: {
			for(int i = 0; i < fu_sum; i++) {
				if(fu[i].rs == NONE)
					return i;
			}
		}
		return NOT_AVAILABLE;
	}
}

int get_result(int op, int vj, int vk) {
	switch(op) {
		case 0: {
			//ld

			break;
		}
		case 1: {
			//st

			break;
		}
		case 2: {
			//move

			break;
		}
		case 3: {
			//neg
			return -vj;
		}
		case 4: {
			//not
			return ~vj;
		}
		case 5: {
			//add
			return vj + vk;
		}
		case 6: {
			//sub
			return vj - vk;
		}
		case 7: {
			//mult
			return vj * vk;
		}
		case 8: {
			//div
			return vj / vk;
		}
		case 9: {
			//and
			return vj & vk;
		}
		case 10: {
			//or
			return vj | vk;
		}
		case 11: {
			//sll
			return vj << vk;
		}
		case 12: {
			//slr
			return vj >> vk;
		}
		case 16: {
			//li

			break;
		}
		case 17: {
			//beqz
			return vj == 0 ? 1 : 0;
		}
		case 18: {
			//bnez
			return vj == 0 ? 0 : 1;
		}
		case 19: {
			//bgtz
			return vj > 0 ? 1 : 0;
		}
		case 20: {
			//blez
			return vj < 0 ? 1 : 0;
		}
		case 32: {
			//addi
			return vj + vk;
		}
		case 33: {
			//subi
			return vj - vk;
		}
		case 34: {
			//multi
			return vj * vk;
		}
		case 35: {
			//divi
			return vj / vk;
		}
		case 36: {
			//andi
			return vj & vk;
		}
		case 37: {
			//ori
			return vj | vk;
		}
		case 38: {
			//beq
			return vj == vk ? 1 : 0;
		}
		case 39: {
			//bne
			return vj != vk ? 1 : 0;
		}
		case 40: {
			//bgt
			return vj > vk ? 1 : 0;
		}
		case 41: {
			//bge
			return vj >= vk ? 1 : 0;
		}
		case 42: {
			//blt
			return vj < vk ? 1 : 0;
		}
		case 43: {
			//ble
			return vj <= vk ? 1 : 0;
		}
		case 48: {
			//b

			break;
		}
	}
}
