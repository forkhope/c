#ifndef L_TOKEN_H
#define L_TOKEN_H

#undef MAXTOKEN
#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

extern int tokentype;
extern char token[];

extern int gettoken(void);

#endif	/* L_TOKEN_H */
