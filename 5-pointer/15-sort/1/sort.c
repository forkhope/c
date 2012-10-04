#include <stdio.h>
#include "lines.h"
#include "qsort.h"

#define MAXLINES 500	/* max #lines to be sorted */

/* sort input lines */
int main(void)
{
	char *lineptr[MAXLINES];	/* pointers to text lines */
	int nlines;					/* number of input lines read */

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort (lineptr, 0, nlines - 1);
		printf("--------After sort--------\n");
		writelines (lineptr, nlines);
		return 0;
	}
	else {
		printf("error: input too big to sort\n");
		return 1;
	}
}
