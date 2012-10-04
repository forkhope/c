#include <stdio.h>

extern unsigned invert(unsigned x, int p, int n);

/* 测试 invert() 函数 */
int main()
{
	unsigned i;

	i = invert(24, 4, 4);
	printf("invert(24, 4, 4) = %u\n", i);
	return 0;
}
