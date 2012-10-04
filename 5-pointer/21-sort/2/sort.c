#include <stdio.h>
#include "lines.h"
#include "lstring.h"
#include "qsort.h"
#define MAXLINES 200	/* max #lines to be sorted */

/* Modify the sort program to handle a -r flag, which indicates sorting in
 * reverse (decreasing) order. Be sure that -r works with -n.
 */
int main(int argc, char *argv[])
{
	char *lineptr[MAXLINES];	/* pointers to text lines */
	int nlines;					/* number of input lines read */
	int c, numeric = 0, reverse = 0;

	/* If the optional argument -n is given, it will sort the input lines
	 * numerically instead of lexicographically.
	 */
	while (--argc > 0 && (*++argv)[0] == '-')
		while ((c = *++argv[0]) != '\0')
			switch (c) {
				case 'n':
					numeric = 1;
					break;
				case 'r':
					reverse = 1;
					break;
				default:
					printf("sort: illegal option %c\n", c);
					return 2;
			}
	/* lineptr是一个指针,指向的变量类型是char *, 则lineptr对应的数据类型是
	 * char **,后面一个 * 表示这是一个指针,前面的char * 表示指针指向的类型
	 * 是 char *; 所以要下面使用 void ** 来进行强制转换,而不是 void *
	 */
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort((void **)lineptr, 0, nlines - 1,
		  (int (*)(const void*, const void*))(numeric ? numcmp : strCmp));
		printf("-------------After sort----------\n");
		if (reverse)
			rorder((void **)lineptr, nlines);
		writelines(lineptr, nlines);
		return 0;
	}
	else {
		printf("error: input too big to sort\n");
		return 1;
	}
}
