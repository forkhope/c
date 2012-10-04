#include <stdio.h>

/* getLine: */
int getLine(char *s, int lim)
{
	int c;
	char *p;

	p = s;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		*p++ = c;
	if (c == '\n')
		*p++ = c;
	*p = '\0';
	return (p - s);
}
