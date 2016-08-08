#ifndef FUNCTIONAL_UNIT_H_
#define FUNCTIONAL_UNIT_H_

#define NONE -1
#define NOT_AVAILABLE -2
#define NOT_RUNNING -5

extern int cicles[];
extern int fu_sum, fu_div, fu_mult, fu_total;

typedef struct {
	int cicles, id, rs, result;
} fu_unit;

fu_unit *initiate_fu(int sum, int div, int mult);

int find_fu(int id, fu_unit *fu);

int empty_fu(fu_unit *fu, int opp);

int get_result(int op, int vj, int vk);

#endif
