#include <stdio.h>

extern int strCmp(const char *s, const char *t);

/* 测试 strCmp() 函数 */
int main(void)
{
	char a[] = "tian";
	char b[] = "tianxia";
	char c[] = "tian";

	printf("比较\"tian\"和\"tianxia\"的结果是:%d\n", strCmp(a, b));
	printf("比较的结果等于 '\\0' - 'x' = %d\n", '\0' - 'x');
	printf("比较\"tianxia\"和\"tian\"的结果是:%d\n", strCmp(b, a));
	printf("比较的结果等于 'x' - '\\0' = %d\n", 'x' - '\0');
	printf("比较\"tian\"和\"tian\"的结果是:%d\n", strCmp(a, c));
	return 0;
}
