#include <stdio.h>
#include "cType.h"
#include "getCh.h"

/* getop: get next character or numeric operand */
int getop(char s[])
{
	int c, i;

	while ((s[0] = c = getCh()) == ' ' || c == '\t')
		;	/* 由判断条件可知,当跳出while循环时,s[0]中的字符不是空白字符 */
	s[1] = '\0';
	if (!isDigit(c) && c != '.')
		return c;	/* not a number */
	i = 0;
	if (isDigit(c))	/* collect integer part */
		while (isDigit(s[++i] = c = getCh()))
				;
	if (c == '.')	/* collect fraction part */
		while (isDigit(s[++i] = c = getCh()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetCh(c);
	return '0';
}
