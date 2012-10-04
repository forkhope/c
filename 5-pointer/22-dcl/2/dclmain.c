#include <stdio.h>
#include <string.h>
#include "token.h"
#include "dcl.h"

/* The difference between 
 * int *f();	// f: function returning pointer to int 
 * and
 * int (*pf)();	// pf: pointer to function returning int 
 * illustrates the problem: * is a prefix operator and it has lower
 * precedence than (), so parentheses are necessary to force the proper
 * association.
 *
 * Make dcl recover from input errors.
 */
int main(void)	/* convert declarator to words */
{
	while (gettoken() != EOF) {	/* 1st token on line */
		/* 第一次读取到的"token"应该是数据类型,保存到datatype[]数组中 */
		strcpy(datatype, token); 	/* is the datatype */
		out[0] = '\0';
		dcl();			/* parse rest of line */
		if (tokentype != '\n') {
			printf("\tsyntax error\n");
			while (gettoken() != '\n')
				;
			continue;
		}
		printf("\t%s: %s %s\n", name, out, datatype);
	}
	return 0;
}
