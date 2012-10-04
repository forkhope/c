#include <stdio.h>
#include "lines.h"
#include "lstring.h"
#include "qsort.h"
#define MAXLINES 200	/* max #lines to be sorted */

/* sort input lines */
int main(int argc, char *argv[])
{
	char *lineptr[MAXLINES];	/* pointers to text lines */
	int nlines;					/* number of input lines read */
	int numeric = 0;			/* 1 if numeric sort */

	/* If the optional argument -n is given, it will sort the input lines
	 * numerically instead of lexicographically.
	 */
	if (argc > 1 && strCmp(argv[1], "-n") == 0)
		numeric = 1;
	/* lineptr是一个指针,指向的变量类型是char *, 则lineptr对应的数据类型是
	 * char **,后面一个 * 表示这是一个指针,前面的char * 表示指针指向的类型
	 * 是 char *; 所以要下面使用 void ** 来进行强制转换,而不是 void *
	 */
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort((void **)lineptr, 0, nlines - 1,
		  (int (*)(const void*, const void*))(numeric ? numcmp : strCmp));
		printf("-------------After sort----------\n");
		writelines(lineptr, nlines);
		return 0;
	}
	else {
		printf("error: input too big to sort\n");
		return 1;
	}
}
