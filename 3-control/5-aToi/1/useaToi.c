#include <stdio.h>

extern int aToi(const char s[]);

/* 测试 aToi() 函数 */
int main()
{
	char s[] = "    230";
	char t[] = "  -378";
	char q[] = "   +34";
	int result;

	result = aToi(s);
	printf("string \"%s\" convert to integer is %d\n", s, result);
	result = aToi(t);
	printf("string \"%s\" convert to integer is %d\n", t, result);
	result = aToi(q);
	printf("string \"%s\" convert to integer is %d\n", q, result);
	return 0;
}
