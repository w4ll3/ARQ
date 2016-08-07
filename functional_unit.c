#include "functional_unit.h"
#include <stdio.h>
#include <stdlib.h>

int cicles[48];

sum_unit *initiate_sfu(int sum) {
	sum_unit *fu = (sum_unit*) malloc(sizeof(sum_unit) * sum);
	return fu;
}

div_unit *initiate_dfu(int div) {
	div_unit *fu = (div_unit*) malloc(sizeof(div_unit) * div);
	return fu;
}

mult_unit *initiate_mfu(int mult) {
	mult_unit *fu = (mult_unit*) malloc(sizeof(mult_unit) * mult);
	return fu;
}
