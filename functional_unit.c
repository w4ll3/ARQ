#include "functional_unit.h"
#include <stdio.h>
#include <stdlib.h>

functional_unit *initiate_fu(int sum, int div, int mul, int load, int store) {
	functional_unit *fu = (functional_unit*) malloc(sizeof(functional_unit));
	fu -> sum = sum;
	fu -> mul = mul;
	fu -> div = div;
	fu -> load = load;
	fu -> store = store;
	fu -> sbusy = 0;
	fu -> mbusy = 0;
	fu -> dbusy = 0;
	fu -> lbusy = 0;
	fu -> stbusy = 0;
	return fu;
}

void fu_stats(functional_unit *fu) {
	int sfree = fu -> sum - fu -> sbusy;
	int dfree = fu -> div - fu -> dbusy;
	int mfree = fu -> mul - fu -> mbusy;
	int lfree = fu -> load - fu -> lbusy;
	int stfree = fu -> store - fu -> stbusy;
	printf("Free functional units:\n\tSum:\t%d.\n\tMul:\t%d.\n\tDiv:\t%d.\n\tLoad:\t%d.\n\tStore:\t%d.\n", sfree, dfree, mfree, lfree, stfree);
}
