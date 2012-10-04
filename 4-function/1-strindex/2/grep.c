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
	int pos;
	int found = 0;

	while (getLine(line, MAXLINE) > 0)
		if ((pos = strindex(line, pattern)) >= 0) {
			printf ("The rightmost occurrence of \"%s\" in\n"
					"%s is %d\n", pattern, line, pos);
			++found;
		}
	return found;
}
