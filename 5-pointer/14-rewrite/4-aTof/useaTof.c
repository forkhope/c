#include <stdio.h>

extern double aTof(const char *s);

/* 测试重写的 aTof() 函数 */
int main(void)
{
	char *number[] = {"48829.34", "-3804.53", "123.45e-6", "1.2e2"};
	int i;

	for (i = 0; i < 4; ++i)
		printf("%g\n", aTof(number[i]));
	return 0;
}
