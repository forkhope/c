#ifndef LSTRING_H
#define LSTRING_H

extern unsigned strLen(const char *s);
extern int strCmp(const char *t, const char *s);
extern char *strCpy(char *dest, const char *src);
extern char *strDup(const char *s);

#endif	/* LSTRING_H */
