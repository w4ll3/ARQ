#ifndef FUNCTIONAL_UNIT_H_
#define FUNCTIONAL_UNIT_H_

typedef struct {
	int sum, div, mul, load, store, sbusy, dbusy, mbusy, lbusy, stbusy;
} functional_unit;

functional_unit *initiate_fu(int sum, int div, int mul, int load, int store);

void fu_stats(functional_unit *fu);

#endif
