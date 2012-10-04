#include <stdio.h>
#include "lines.h"
#include "qsort.h"

#define MAXLINES 400	/* max #lines to be sorted */
#define BUFSIZE  10000	/* 存放所有输入行的缓冲区 */

/* Rewrite readlines to store lines in an array supplied by main, rather
 * than calling alloc to maintain storage. How much faster is the program?
 */
int main(void)
{
	int nlines;
	char *lineptr[MAXLINES], linebuf[BUFSIZE];

	if ((nlines = readlines(lineptr, MAXLINES, linebuf, BUFSIZE)) >= 0) {
		qsort (lineptr, 0, nlines - 1);
		printf ("------- After sort --------\n");
		writelines(lineptr, nlines);
		return 0;
	}
	else {
		printf("error: input too big to sort\n");
		return 1;
	}
}
