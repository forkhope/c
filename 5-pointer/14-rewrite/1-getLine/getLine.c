#include <stdio.h>

/* 使用指针替换字符数组来重写 getLine() 函数 */
int getLine(char *s, int lim)
{
	char *p;
	int c;

	p = s;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		*p++ = c;
	if (c == '\n')
		*p++ = c;
	*p = '\0';
	/* 返回值是 (p - s),而不是使用int len变量来统计字符数 */
	return (p - s);
}
