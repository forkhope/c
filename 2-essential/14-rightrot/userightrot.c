#include <stdio.h>

extern unsigned rightrot(unsigned x, int n);

/* 测试 rightrot() 函数 */
int main()
{
	unsigned x;
	int n;

	for (x = 0; x < 700; x += 49)
		for (n = 1; n < 8; ++n)
			printf("%u, %d: %u\n", x, n, rightrot(x, n));
	return 0;
}
