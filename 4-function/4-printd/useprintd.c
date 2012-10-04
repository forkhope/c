#include <stdio.h>

extern void printd(int n);

/* 测试 printd() 函数 */
int main(void)
{
	int i;

	i = 123458;
	printd(i);
	putchar('\n');
	return 0;
}
