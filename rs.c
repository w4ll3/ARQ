#include <stdio.h>
#include <stdlib.h>
#include "rs.h"

int rs_sum = 0, rs_div = 0, rs_sub = 0, rs_mult = 0, rs_total = 0;

reserve_station *initiate_rs(int sum, int div, int sub, int mult) {
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
		if(rs -> busy == 0)
			return rs -> id;
	}
	return -1;
}

int empty_sub(reserve_station *rs) {
	for(int i = 0; i < rs_sub; i++) {
		if(rs -> busy == 0)
			return rs -> id;
	}
	return -1;
}

int empty_div(reserve_station *rs) {
	for(int i = 0; i < rs_div; i++) {
		if(rs -> busy == 0)
			return rs -> id;
	}
	return -1;
}

int empty_mult(reserve_station *rs) {
	for(int i = 0; i < rs_mult; i++) {
		if(rs -> busy == 0)
			return rs -> id;
	}
	return -1;
}

void show_rs(reserve_station *rs) {
	for(int i = 0; i < rs_sum; i++) {
		printf("+: [%.3d] | %s | %d | %d | %d | %d | %d | %d |\n", rs[i].id, rs[i].op, rs[i].qj, rs[i].qk, rs[i].vj, rs[i].vk, rs[i].a, rs[i].busy);
	}

	for(int i = rs_sum; i < rs_total - rs_mult - rs_div; i++) {
		printf("-: [%.3d] | %s | %d | %d | %d | %d | %d | %d |\n", rs[i].id, rs[i].op, rs[i].qj, rs[i].qk, rs[i].vj, rs[i].vk, rs[i].a, rs[i].busy);
	}

	for(int i = rs_total - rs_mult - rs_div; i < rs_total - rs_mult; i++) {
		printf("/: [%.3d] | %s | %d | %d | %d | %d | %d | %d |\n", rs[i].id, rs[i].op, rs[i].qj, rs[i].qk, rs[i].vj, rs[i].vk, rs[i].a, rs[i].busy);
	}

	for(int i = rs_total - rs_mult; i < rs_total; i++) {
		printf("*: [%.3d] | %s | %d | %d | %d | %d | %d | %d |\n", rs[i].id, rs[i].op, rs[i].qj, rs[i].qk, rs[i].vj, rs[i].vk, rs[i].a, rs[i].busy);
	}
}
