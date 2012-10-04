#include <stdio.h>
#include <ctype.h>
#include "libgetch.h"

int getpoint(char *s)
{
	int c;

	while ((c = getch()) == ' ' || c == '\t')
		;
	if (c == EOF || !isdigit(c))
		return c;
	for (*s++ = c; isdigit(c = getch()); *s++ = c)
		;
	*s = '\0';
	return NUMBER;
}
