#include "processor.h"
#include "memory.h"
#include "register.h"
#include "line.h"

int EXIT_SIGNAL = 1;

int pc = 0;
int search = 0;

void fetch(memory *mem, line *li, int *pc) {
	int count = 0;
	while (count != search) {
		putIn(mem -> data[mem -> size - *pc], li);
		*pc += 1;
		count++;
	}
	showLine(li);
}

void issue(int *pc) {

}

void execute(int *pc) {

}
