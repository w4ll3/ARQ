#ifndef PROCESSOR_H_
#define PROCESSOR_H_

#include "memory.h"
#include "line.h"

extern int pc;
extern int search;

void fetch(memory *mem, line *li, int *pc);

void issue(int *pc);

void execute(int *pc);

#endif
