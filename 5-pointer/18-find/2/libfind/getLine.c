#include <stdio.h>

/* getLine: read a lint into s, return length */
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
	return p - s;
}
