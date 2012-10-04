#include <stdio.h>
#include "lstring.h"
#include "alloc.h"

#define MAXLEN	1000	/* 每行最多包含的字符数 */

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

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
	/*****
	int i;
	for (i = 0; i < nlines; ++i)
		printf("%s\n", lineptr[i]);
	*/
	/* Since lineptr is itself the name of an array, it can be treated as
	 * a pointer in the same manner as in our earlier examples, and 
	 * writelines can be written instead as:
	 */
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}

static int getLine(char *s, int lim)
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
