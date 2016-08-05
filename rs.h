#ifndef RS_H_
#define RS_H_

typedef struct {
	int qj, qk, vj, vk, a, busy, id;
	char *op;
} reserve_station;

extern int rs_sum, rs_div, rs_sub, rs_mult, rs_total;

reserve_station *initiate_rs(int sum, int div, int sub, int mult);

int empty_sum(reserve_station *rs);

int empty_sub(reserve_station *rs);

int empty_div(reserve_station *rs);

int empty_mult(reserve_station *rs);

void show_rs(reserve_station *rs);

#endif
