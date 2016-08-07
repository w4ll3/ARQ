#ifndef RS_H_
#define RS_H_

#include "register.h"

#define EMPTY_RS -1
#define READY -2
#define REG_1I 0
#define REG_1L 1
#define REG_2 2
#define REG_2I 3
#define REG_2L 4
#define REG_3 5
#define L 6

typedef struct {
	int op, qj, qk, vj, vk, a, busy, id;
} reserve_station;

extern int rs_sum, rs_div, rs_sub, rs_mult, rs_total;

reserve_station *initiate_rs(int sum, int sub, int div, int mult);

int empty_sum(reserve_station *rs);

int empty_sub(reserve_station *rs);

int empty_div(reserve_station *rs);

int empty_mult(reserve_station *rs);

int busy_sum(reserve_station *rs);

int busy_sub(reserve_station *rs);

int busy_div(reserve_station *rs);

int busy_mult(reserve_station *rs);

int empty_rs(reserve_station *rs, int opp);

int busy_rs(reserve_station *rs);

void show_rs(reserve_station *rs);

void set_rs(reserve_station *rs, int id, int type, char *inst, int op, reg_bank *reg);

#endif
