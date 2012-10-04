#include <stdio.h>

extern int getLine(char *s, int lim);

#define MAXLINE	1000	/* maximum input line length */

/* 测试重写后的 getLine() 函数 */
int main(void)
{
	char line[MAXLINE];

	while (getLine(line, MAXLINE) > 0)
		printf("获得的字符串是: %s", line);
	return 0;
}
