#include <stdio.h>

extern void swap(int *px, int *py);

/* 测试 swap() 函数 */
int main(void)
{
	int i, j;

	i = 58;
	j = 37;
	printf ("Before swap, i = %d, j = %d\n", i, j);
	swap (&i, &j);
	printf ("After  swap, i = %d, j = %d\n", i, j);
	return 0;
}
