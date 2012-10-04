#include <stdio.h>

extern unsigned setbits(unsigned x, int p, int n, unsigned y);

/* 测试 setbits() 函数 */
int main()
{
	unsigned i;

	i = setbits(24, 4, 4, 10);
	printf("setbits(24, 4, 4, 10) = %u\n", i);
	return 0;
}
