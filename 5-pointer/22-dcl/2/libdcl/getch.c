#include <stdio.h>

#define BUFSIZE		100
static int bufp = 0;		/* next free position in buf */
static char buf[BUFSIZE];	/* buffer for ungetch */

int getch(void)	/* get a (possibly pushed-back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(const int c)	/* push character back on input */
{
	if (bufp < BUFSIZE)
		buf[bufp++] = c;
	else
		printf("ungetch: too many characters\n");
}
