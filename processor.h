#ifndef PROCESSOR_H_
#define PROCESSOR_H_

#include "memory.h"
#include "line.h"
#include "rs.h"
#include "register.h"
#include "functional_unit.h"

#define	LD		0
#define	ST		1
#define	MOVE	2
#define	NEG		3
#define	NOT		4
#define	ADD		5
#define	SUB		6
#define	MULT	7
#define	DIV		8
#define	AND		9
#define	OR		10
#define	SLL		11
#define	SLR		12
#define	LI		16
#define	BEQZ	17
#define	BNEZ	18
#define	BGTZ	19
#define	BLEZ	20
#define	ADDI	32
#define	SUBI	33
#define	MULTI	34
#define	DIVI	35
#define	ANDI	36
#define	ORI		37
#define	BEQ		38
#define	BNE		39
#define	BGT		40
#define	BGE		41
#define	BLT		42
#define	BLE		43
#define	B		48

extern int pc;
extern int search;

void fetch(memory *mem, line *li, int *pc, int *ic);

void issue(int *pc, line *li, reserve_station *rs, reg_bank *reg);

void execute(int *pc, reserve_station *rs, fu_unit *fu);

void cdb(int *pc, reserve_station *rs, int id, fu_unit *fu, int flag);
#endif
