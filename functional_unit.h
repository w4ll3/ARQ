#ifndef FUNCTIONAL_UNIT_H_
#define FUNCTIONAL_UNIT_H_

extern int cicles[];

typedef struct {
	int cicles, id, rs;
} sum_unit;

typedef struct {
	int cicles, id, rs;
} div_unit;

typedef struct {
	int cicles, id, rs;
} mult_unit;

sum_unit *initiate_sfu(int sum);

div_unit *initiate_dfu(int div);

mult_unit *initiate_mfu(int mult);

#endif
