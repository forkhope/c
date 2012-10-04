#ifndef LIBGETCH_H
#define LIBGETCH_H

extern int getch(void);
extern void ungetch(const int c);

#define NUMBER	'0'
extern int getpoint(char *s);

extern int aToi(const char *s);

#endif	/* LIBGETCH_H */
