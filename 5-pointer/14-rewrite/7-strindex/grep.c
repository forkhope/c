#include <stdio.h>

#define MAXLINE	1000
char *pattern = "ould";

extern int getLine(char *s, int lim);
extern int strindex(const char *s, const char *t);

/* 测试重写的 strindex() 函数 */
int main(void)
{
	char line[MAXLINE];
	int found, ret;
	
	while (getLine(line, MAXLINE) > 0) {
		ret = strindex(line, pattern);
		if (ret != -1) {
			printf("%s", line);
			++found;
		}
	}
	return found;
}
