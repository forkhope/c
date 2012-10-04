#include <stdio.h>
#include <stdlib.h>
#include "libhash.h"
#include "lstring.h"

void unDef(const char *name)
{
	struct nlist *np, *temp;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) 
		printf("error: The macro %s was not defined\n", name);
	else {
		hashval = hash(name);
		if ((temp = hashtab[hashval]) == np)
			hashtab[hashval] = np->next;
		else {
			for ( ; temp->next != np; temp = temp->next)
				;
			temp->next = np->next;
		}
		free(np->name);
		free(np->defn);
		free(np);
	}
}
