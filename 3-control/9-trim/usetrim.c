#include <stdio.h>

extern int trim(char s[]);
int getLine(char s[], int limit);

/* 测试 trim() 函数 */
int main()
{
#define MAXLINE	1000	/* maximum input line length */
	char s[MAXLINE];

	while (getLine(s, MAXLINE) > 0) {
		trim(s);
		printf("%s\n", s);
	}
	return 0;
}

/* getLine: read a line into s, return length. 重温getLine()函数的写法 */
int getLine(char s[], int limit)
{
	int i, c;
	/* 由于 trim() 函数会将尾部的空格、列表符和回车换行符都去掉,为了看到
	 * 效果,这里会接收多个回车换行符,即for循环的判断条件中不包含 c != '\n'
	 */
	for (i = 0; i < limit-1 && (c = getchar()) != EOF; ++i)
		s[i] = c;
	s[i] = '\0';
	return i;
}
