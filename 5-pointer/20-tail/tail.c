#include <stdio.h>
#include "aToi.h"
#include "cType.h"
#include "lines.h"
#define MAXLINES 500	/* max #lines can be inputed */

/* Write the program tail, which prints the last n lines of its input. By
 * default, n is set to 10, let us say, but it can be changed by an
 * optional argument so that, tail -n, prints the last n lines.
 */
int main(int argc, char *argv[])
{
	int lastnum, nlines;
	char *lineptr[MAXLINES], *p;

	
	if (argc == 1)
		lastnum = 10;	/* 如果没有给出参数,则默认打印末尾 10 行 */
	else if (argc == 2 && (*++argv)[0] == '-') {
		p = argv[0];
		while (*++p != '\0')
			if (!is_digit(*p)) {
				printf("Usage: tail -n, n must a integer\n");
				return 1;
			}
		lastnum = aToi(++argv[0]);	/* ++argv[0] 越过前面的'-'字符 */
	}
	else {
		printf("Usage: tail -n, n must a integer\n");
		return 2;
	}
	if ((nlines = readlines(lineptr, MAXLINES)) > 0) {
		printf("------------分割符-------------------\n");
		if (lastnum >= nlines)
			writelines(lineptr, nlines);
		else 
			writelines(lineptr + nlines - lastnum, lastnum);
	}
	return 0;
}
