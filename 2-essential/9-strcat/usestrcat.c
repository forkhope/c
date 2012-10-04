#include <stdio.h>

extern void strCat(char s[], const char t[]);

/* 测试 strCat 函数 */
int main()
{
	char s[] = "tian";
	const char t[] = "xia";

	strCat(s, t);
	printf("%s\n", s);
	return 0;
}
