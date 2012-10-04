#include <stdio.h>
#include "lstring.h"
#include "getLine.h"
#define MAXLINE 1000	/* maximum length of input line */

/* find: print lines that match pattern from 1st arg */
int main(int argc, char *argv[])
{
	char line[MAXLINE];	/* storage input lines */
	int found = 0;

	if (argc != 2)
		printf("Usage: find pattern\n");
	else 
		while (getLine(line, MAXLINE) > 0)
			if (strStr(line, argv[1]) != NULL) {
				printf("%s", line);
				++found;
			}
	return found;
}
