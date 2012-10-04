#include <stdio.h>
#include "lstring.h"
#include "alloc.h"
#define MAXLEN	300		/* maximum length of any input line */

static int getLine(char *s, int lim);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = getLine(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0';	/* delete newline */
			strCpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

/* writelines: write input lines */
void writelines(char *lineptr[], int nlines)
{
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}

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
