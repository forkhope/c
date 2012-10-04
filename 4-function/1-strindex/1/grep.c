#include <stdio.h>
#define MAXLINE	1000	/* maximum input line length */

extern int strindex(const char s[], const char t[]);
extern int getLine(char s[], int lim);

char pattern[] = "ould";	/* pattern to search for */

/* 测试 strindex()、getLine() 函数
 * find all lines matching pattern
 */
int main()
{
	char line[MAXLINE];
	int found = 0;

	while (getLine(line, MAXLINE) > 0)
		if (strindex(line, pattern) >= 0) {
			printf ("%s", line);
			++found;
		}
	return found;
}
