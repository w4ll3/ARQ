#include "line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

line *initiate() {
	line *li = (line*) malloc(sizeof(line));
	li -> beggin = (node*) malloc(sizeof(node));
	li -> end = li -> beggin;
	return li;
}

void putIn(char *data, line *li) {
	node *new = (node*) malloc(sizeof(node));
	new -> data = data;
	new -> next = li -> beggin;
	li -> beggin = new;
}

void showLine(line *li) {
  node *p = li -> beggin;
  printf("Beggin -> [");
  while (p) {
    printf("%s", p -> data);
    p = p->next;
    if (p)
      printf("], [");
  }
  printf("].\n");
}

void showFirst(line li) {
  if (!li.beggin) {
    printf("Empty line.\n");
  } else {
    printf("First -> [%s].\n", li.beggin->data);
  }
}

void showLast(line li) {
  if (!li.beggin)
    printf("Empty line.\n");
  else {
    node *p = li.beggin;
    while (p->next) {
      p = p->next;
    }
    printf("Last -> [%s].\n", p->data);
  }
}

int showSize(line li) {
  if (!li.beggin) {
    printf("Empty line.\n");
    return 0;
  } else {
    int size = 1;
    node *p = li.beggin;
    while (p->next) {
      p = p->next;
      size++;
    }
    return size;
  }
}

void putOut(line *li) {
	node *elem;
	elem = li -> beggin -> next;
	free(li -> beggin);
	li -> beggin = elem;
}

void clearLine(line *li) {
	node *atual, *next;
	atual = li->beggin;
	while (atual) {
		next = atual->next;
		free(atual);
		atual = next;
	}
	li->beggin = NULL;
	li->end = NULL;
}

int isEmpty(line *li) { return li -> beggin -> data == NULL ? 1 : 0; }
