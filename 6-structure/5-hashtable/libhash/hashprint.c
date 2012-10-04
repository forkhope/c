#include <stdio.h>
#include "libhash.h"

void hashprint()
{
	struct nlist **np, *lp;

	for (np = hashtab; np < hashtab + HASHSIZE; ++np)
		for (lp = *np; lp != NULL; lp = lp->next)
			printf("name: %s, defn: %s\n", lp->name, lp->defn);
}
