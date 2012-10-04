#ifndef LIBHASH_H
#define LIBHASH_H

struct nlist {		/* table entry: */
	struct nlist *next;		/* next entry in chain */
	char *name;				/* defined name */
	char *defn;				/* replacement text */
};

#define HASHSIZE	101		/* hash表数组的大小 */
extern struct nlist *hashtab[];	/* hash表数组 */

extern unsigned hash(const char *s);
extern struct nlist *lookup(const char *s);
extern struct nlist *install(const char *name, const char *defn);
extern void hashprint();

extern int getword(char *word, int lim);

#endif	/* LIBHASH_H */
