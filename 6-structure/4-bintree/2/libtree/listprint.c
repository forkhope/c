#include <stdio.h>
#include "libtree.h"

void listprint(struct wordlist *list)
{
	while (list != NULL) {
		printf("%6d", list->linenum);
		list = list->next;
	}
	printf("\n");
}
