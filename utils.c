#include "utils.h"

list *initialize_list() {
	list *llist = (list*) malloc(sizeof(list));
	return llist;
}

void insert_list(list *llist, char *label, int laddress, int *lcount) {
	llist[*lcount].label = label;
	llist[*lcount].laddress = laddress;
	*lcount += 1;
	llist = (list*) realloc(llist, *lcount * 2);
}

void show_list(list *llist, int size) {
	int i = 0;
	while(i < size) {
		printf("[%s]  [%d]\n", llist[i].label, llist[i].laddress);
		i++;
	}
	printf("\n");
}
