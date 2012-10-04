#include <stdio.h>

#define BUFSIZE	100
static char buf[BUFSIZE];
static char *bufp = buf;

int getch(void)
{
	return (bufp > buf) ? *--bufp : getchar();
}

void ungetch(const int c)
{
	if (bufp < buf + BUFSIZE)
		*bufp++ = c;
	else
		printf("ungetch: too many characters\n");
}
