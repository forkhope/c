#include <stdio.h>
#include <stdlib.h>
#include "libtree.h"

struct wordlist *addlist(int linenum)
{
	struct wordlist *new;

	new = (struct wordlist *)malloc(sizeof(struct wordlist));
	if (new != NULL) {
		new->next = NULL;
		new->linenum = linenum;
	}
	return new;
}
