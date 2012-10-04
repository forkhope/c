#include <stdio.h>

extern int any(const char s1[], const char s2[]);

/* 测试 any() 函数 */
int main()
{
	const char s1[] = "tianxia";
	const char s2[] = "ai";
	int i;

	i = any(s1, s2);
	if (i != -1)
		printf("%s的第%d个字符在%s中第一次出现\n", s1, i, s2);
	return 0;
}
