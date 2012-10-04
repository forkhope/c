#include <stdio.h>

extern int aToi(char s[]);

/* 测试 aToi()函数 */
int main()
{
	int i;
	char s[] = "4826";

	i = aToi(s);
	printf("\"%s\" 转换为整数是: %d\n", s, i);
	return 0;
}
