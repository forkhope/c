#include <stdio.h>	/* 声明 getchar() 函数 */
#define MAXLEN	1000	/* maximum length of any input line */

static int getLine(char *s, int lim);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines, char linebuf[], int bufsize)
{
	int len, bufp, nlines;

	nlines = 0;
	bufp = 0;
	while ((len = getLine(linebuf+bufp, MAXLEN)) > 0)
		if (nlines >= maxlines || (bufp += len) >= bufsize)
			return -1;
		else {
			linebuf[bufp - 1] = '\0';
			lineptr[nlines++] = linebuf + bufp - len; /* old bufp */
		}
	return nlines;
}

/* writelines: write input lines */
void writelines(char *lineptr[], int nlines)
{
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}

/* getLine: read a line into s, return length */
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
