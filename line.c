#include <stdio.h>
#include <string.h>
#include "line.h"

void initiate(line *li) {
	li -> beggin = NULL;
	li -> end = NULL;
	printf("\t\tFila inicializada.\n");
}

void putIn(int key, char *data, line *li) {
	node *new = (node*) malloc(sizeof(node));
	new -> key = key;
	new -> data = data;
	new -> next = NULL;
	if(!li -> beggin) {
		li -> beggin = new;
	} else {
		li -> end -> next = new;
	}
	li -> end = new;
}

void showLine(line li) {
	node *p = li.beggin;
	printf("Beggin -> [");
	while(p) {
		printf("%d, %s", p -> key, p -> data);
		p = p -> next;
		if(p) printf("], [");
	}
	printf("].\n");
}

void showFirst(line li) {
	if(!li.beggin) {
		printf("Empty line.\n");
	} else {
		printf("First -> [%d, %s].\n", li.beggin -> key, li.beggin -> data);
	}
}

void showLast(line li) {
	if(!li.beggin) printf("Empty line.\n");
	else {
		node *p = li.beggin;
		while(p -> next) {
			p = p -> next;
		}
		printf("Last -> [%d, %s].\n", p -> key, p -> data);
	}
}

int showSize(line li) {
	if(!li.beggin) {
		printf("Empty line.\n");
		return 0;
	} else {
		int size = 1;
		node *p = li.beggin;
		while(p -> next) {
			p = p -> next;
			size++;
		}
		return size;
	}
}

void putOut(line *line) {
	node *elem;
	elem = line -> beggin;
	if(!elem) {
		printf("Empty line.\n");
	} else {
		line -> beggin = elem -> next;
		free(elem);
	}
}

void clearLine(line *line) {
	node *atual, *next;
	atual = line -> beggin;
	while(atual) {
		next = atual -> next;
		free(atual);
		atual = next;
	}
	line -> beggin = NULL;
	line -> end = NULL;
}
