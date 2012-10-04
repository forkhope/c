#ifndef LSTRING_H
#define LSTRING_H

extern char *strCpy(char *dest, const char *src);
extern int strCmp(const char *dest, const char *src);
extern int numcmp(const char *dest, const char *src);
extern int foldcmp(const char *s1, const char *s2);

#endif	/* LSTRING_H */
