#include <stdio.h>

extern int bitcount(unsigned x);

/* 测试 bitcount() 函数 */
int main()
{
	unsigned x = 39;
	int count;

	count = bitcount(x);
	printf("The number of 1-bits in %d is %d\n", x, count);
	return 0;
}
