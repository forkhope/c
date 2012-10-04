#include <stdio.h>
#include <string.h>
#include "token.h"

char datatype[MAXTOKEN];	/* data type = char, int, etc. */
char name[MAXTOKEN];		/* identifier name */
char out[1000];

void dirdcl(void);

/* dcl: parse a declarator */
void dcl(void)
{
	int ns;

	for (ns = 0; gettoken() == '*'; ++ns)
		;
	dirdcl();
	while (ns-- > 0)
		strcat(out, " pointer to");
}

/* dirdcl: parse a direct declarator */
void dirdcl(void)
{
	int type;

	if (tokentype == '(') {
		dcl();
		if (tokentype != ')') {
			printf("\terror: missing )\n");
			while (gettoken() != '\n')
				;
			return ;
		}
	}
	else if (tokentype == NAME)
		strcpy(name, token);
	else {
		printf("\terror: expected name of (dcl)\n");
		while (gettoken() != '\n')
			;
		return ;
	}
	while ((type = gettoken()) == PARENS || type == BRACKETS)
		if (type == PARENS) {
			strcat(out, " function returning");
		}
		else {
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
}
