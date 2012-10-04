#ifndef	L_TOKEN_H
#define L_TOKEN_H

#undef MAXLEN
#define MAXLEN 100

enum { NAME, PARENS, BRACKETS };

extern int tokentype;
extern char token[];
extern char datatype[];
extern char name[];
extern char out[];

int gettoken(void);

#endif	/* L_TOKEN_H */
