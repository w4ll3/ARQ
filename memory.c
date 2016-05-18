#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cells {
	int bit;
} Cell;

typedef struct memory {
	struct *cell;
} Memory;

void left_shift() {

}

void right_shitf() {

}

void set_memsize(Memory *m) {
	do {
		int size;
		printf("Enter the size of the system memory (Use MB(MegaBytes)): ");
		scanf("%d", &size);
		if(size <= 0)
		m -> cell = malloc(sizeof(Cell) * (size * 1048576));
		if(size <= 0)
			printf("Please enter a value bigger than one (1)\n");
	} while(size <= 0);
}

