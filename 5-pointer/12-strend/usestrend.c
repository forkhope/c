#include <stdio.h>

extern int strend(const char *s, const char *t);

/* 测试 strend() 函数 */
int main(void)
{
	char *p = "tianxia";
	char *q = "xia";
	char *t = "tian";

	printf("strend(p, q) = %d\n", strend(p, q));
	printf("strend(p, t) = %d\n", strend(p, t));
	return 0;
}
