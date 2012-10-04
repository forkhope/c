#include <stdlib.h>
#include "lstring.h"
#include "libhash.h"

/* install: put (name, defn) in hashtab, install uses loopupto determine
 * whether the name being installed is already present; if so, the new
 * definition will supersede the old one. Otherwise, a new entry is created
 * install returns NULL if for any reason there is no room for a new entry.
 */
struct nlist *install(const char *name, const char *defn)
{
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) {	/* not found */
		np = (struct nlist*)malloc(sizeof(*np));
		if (np == NULL || (np->name = strDup(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}
	else 				/* already there */
		free(np->defn);	/* free previous defn */
	if ((np->defn = strDup(defn)) == NULL)
		return NULL;
	return np;
}
