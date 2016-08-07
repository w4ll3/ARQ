#include <stdio.h>
#include <stdlib.h>
#include "rs.h"
#include "processor.h"

int rs_sum = 0, rs_div = 0, rs_sub = 0, rs_mult = 0, rs_total = 0;

reserve_station *initiate_rs(int sum, int sub, int div, int mult) {
	reserve_station *rs = (reserve_station*) malloc(sizeof(reserve_station) * (sum + div + sub + mult));

	rs_sum = sum;
	rs_sub = sub;
	rs_div = div;
	rs_mult = mult;
	rs_total = rs_mult + rs_div + rs_sub + rs_sum;

	for(int i = 0; i < rs_total; i++)
		rs[i].id = i;
	return rs;
}

int empty_sum(reserve_station *rs) {
	for(int i = 0; i < rs_sum; i++) {
		if(rs[i].busy == 0)
			return rs[i].id;
	}
	return EMPTY_RS;
}

int empty_sub(reserve_station *rs) {
	for(int i = rs_sum; i < rs_total - rs_mult - rs_div; i++) {
		if(rs[i].busy == 0)
			return rs[i].id;
	}
	return EMPTY_RS;
}

int empty_div(reserve_station *rs) {
	for(int i = rs_total - rs_mult - rs_div; i < rs_total - rs_mult; i++) {
		if(rs[i].busy == 0)
			return rs[i].id;
	}
	return EMPTY_RS;
}

int empty_mult(reserve_station *rs) {
	for(int i = rs_total - rs_mult; i < rs_total; i++) {
		if(rs[i].busy == 0)
			return rs[i].id;
	}
	return EMPTY_RS;
}

int busy_sum(reserve_station *rs) {
	for(int i = 0; i < rs_sum; i++) {
		if(rs[i].busy != 0)
			return rs[i].id;
	}
	return EMPTY_RS;
}

int busy_sub(reserve_station *rs) {
	for(int i = rs_sum; i < rs_total - rs_mult - rs_div; i++) {
		if(rs[i].busy != 0)
			return rs[i].id;
	}
	return EMPTY_RS;
}

int busy_div(reserve_station *rs) {
	for(int i = rs_total - rs_mult - rs_div; i < rs_total - rs_mult; i++) {
		if(rs[i].busy != 0)
			return rs[i].id;
	}
	return EMPTY_RS;
}

int busy_mult(reserve_station *rs) {
	for(int i = rs_total - rs_mult; i < rs_total; i++) {
		if(rs[i].busy != 0)
			return rs[i].id;
	}
	return EMPTY_RS;
}

int empty_rs(reserve_station *rs, int opp) {
	switch(opp) {
		case 5:
		case 32: {
			return empty_sum(rs);
		}
		case 6:
		case 33: {
			return empty_sub(rs);
		}
		case 7:
		case 34: {
			return empty_mult(rs);
		}
		case 8:
		case 35: {
			return empty_div(rs);
		}
		default: {
			int flag = empty_sum(rs);
			if(flag == EMPTY_RS)
				return empty_sub(rs);
			return flag;
		}
	}
}

void show_rs(reserve_station *rs) {
	for(int i = 0; i < rs_sum; i++) {
		printf("+: [%.3d] | %d | %d | %d | %d | %d | %d | %d |\n", rs[i].id, rs[i].op, rs[i].qj, rs[i].qk, rs[i].vj, rs[i].vk, rs[i].a, rs[i].busy);
	}

	for(int i = rs_sum; i < rs_total - rs_mult - rs_div; i++) {
		printf("-: [%.3d] | %d | %d | %d | %d | %d | %d | %d |\n", rs[i].id, rs[i].op, rs[i].qj, rs[i].qk, rs[i].vj, rs[i].vk, rs[i].a, rs[i].busy);
	}

	for(int i = rs_total - rs_mult - rs_div; i < rs_total - rs_mult; i++) {
		printf("/: [%.3d] | %d | %d | %d | %d | %d | %d | %d |\n", rs[i].id, rs[i].op, rs[i].qj, rs[i].qk, rs[i].vj, rs[i].vk, rs[i].a, rs[i].busy);
	}

	for(int i = rs_total - rs_mult; i < rs_total; i++) {
		printf("*: [%.3d] | %d | %d | %d | %d | %d | %d | %d |\n", rs[i].id, rs[i].op, rs[i].qj, rs[i].qk, rs[i].vj, rs[i].vk, rs[i].a, rs[i].busy);
	}
}

int busy_rs(reserve_station *rs) {
	int result = busy_sum(rs);
	if(result != EMPTY_RS)
		return result;
	result = busy_sub(rs);
	if(result != EMPTY_RS)
		return result;
	result = busy_div(rs);
	if(result != EMPTY_RS)
		return result;
	return busy_mult(rs);
}

void set_rs(reserve_station *rs, int id, int type, char *inst, int op, reg_bank *reg) {
	switch(type) {
		case REG_1I: {

			break;
		}
		case REG_1L: {
			rs[id].op = op;
			rs[id].qj = -1;
			rs[id].qk = -1;
			rs[id].vj = -1;
			rs[id].vk = -1;
			rs[id].busy = 1;
			rs[id].a = binary_to_decimal(inst, 11, 31);
			int reg_id = binary_to_decimal(inst, 6, 10);
			if(reg[reg_id].qi == AVAILABLE)
				rs[id].vj = binary_to_decimal(reg[reg_id].data, 0, 31);
			else
				rs[id].qj = reg[reg_id].qi;
			break;
		}
		case REG_2: {
			rs[id].op = op;
			rs[id].qj = -1;
			rs[id].qk = -1;
			rs[id].vj = -1;
			rs[id].vk = -1;
			rs[id].busy = 1;
			rs[id].a = -1;
			int reg_id = binary_to_decimal(inst, 6, 10);
			if(reg[reg_id].qi == AVAILABLE)
				rs[id].vj = binary_to_decimal(reg[reg_id].data, 0, 31);
			else
				rs[id].qj = reg[reg_id].qi;
			reg[reg_id].qi = id;

			reg_id = binary_to_decimal(inst, 11, 15);
			if(reg[reg_id].qi == AVAILABLE)
				rs[id].vk = binary_to_decimal(reg[reg_id].data, 0, 31);
			else
				rs[id].qk = reg[reg_id].qi;
			break;
		}
		case REG_2I: {
			rs[id].op = op;
			rs[id].qj = -1;
			rs[id].qk = -1;
			rs[id].vj = -1;
			rs[id].vk = binary_to_decimal(inst, 16, 31);
			rs[id].busy = 1;
			rs[id].a = -1;
			int reg_id = binary_to_decimal(inst, 11, 15);
			if(reg[reg_id].qi == AVAILABLE)
				rs[id].vj = binary_to_decimal(reg[reg_id].data, 0, 31);
			else
				rs[id].qj = reg[reg_id].qi;

			reg_id = binary_to_decimal(inst, 6, 10);
			reg[reg_id].qi = id;
			break;
		}
		case REG_2L: {
			rs[id].op = op;
			rs[id].qj = -1;
			rs[id].qk = -1;
			rs[id].vj = -1;
			rs[id].vk = -1;
			rs[id].busy = 1;
			rs[id].a = -1;
			int reg_id = binary_to_decimal(inst, 6, 10);
			if(reg[reg_id].qi == AVAILABLE)
				rs[id].vj = binary_to_decimal(reg[reg_id].data, 0, 31);
			else
				rs[id].qj = reg[reg_id].qi;

			reg_id = binary_to_decimal(inst, 11, 15);
			if(reg[reg_id].qi == AVAILABLE)
				rs[id].vk = binary_to_decimal(reg[reg_id].data, 0, 31);
			else
				rs[id].qk = reg[reg_id].qi;
			break;
		}
		case REG_3: {
			rs[id].op = op;
			rs[id].qj = -1;
			rs[id].qk = -1;
			rs[id].vj = -1;
			rs[id].vk = -1;
			rs[id].busy = 1;
			rs[id].a = -1;
			int reg_id = binary_to_decimal(inst, 11, 15);
			printf("reg_id %d\n", reg_id);
			if(reg[reg_id].qi == AVAILABLE)
				rs[id].vj = binary_to_decimal(reg[reg_id].data, 0, 31);
			else
				rs[id].qj = reg[reg_id].qi;

			reg_id = binary_to_decimal(inst, 16, 20);
			if(reg[reg_id].qi == AVAILABLE)
				rs[id].vk = binary_to_decimal(reg[reg_id].data, 0, 31);
			else
				rs[id].qk = reg[reg_id].qi;

			reg_id = binary_to_decimal(inst, 6, 10);
			reg[reg_id].qi = id;
			break;
		}
		case L: {
			rs[id].op = op;
			rs[id].qj = -1;
			rs[id].qk = -1;
			rs[id].vj = -1;
			rs[id].vk = -1;
			rs[id].busy = 1;
			rs[id].a = binary_to_decimal(inst, 6, 31);
			break;
		}
		default: break;
	}
}
