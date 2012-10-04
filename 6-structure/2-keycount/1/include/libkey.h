#ifndef LIBKEY_H
#define LIBKEY_H

struct key {
	char *word;
	int count;
};
extern struct key keytab[];
extern int nkeys;

extern int getword(char *word, int lim);
extern int strcmp(const char *dest, const char *src);
extern int binsearch(char *, struct key *, int);

#endif	/* LIBKEY_H */
