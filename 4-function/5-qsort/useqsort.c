#include <stdio.h>

extern void qsort(int v[], int left, int right);

/* 测试 qsort() 函数 */
int main(void)
{
	int v[] = {9, 20, 38, 19, 40, 3, 8, 99, 6, 32};
	int i;

	printf("Before sort:");
	for (i = 0; i < 10; ++i)
		printf(" %2d", v[i]);
	putchar('\n');

	qsort(v, 0, 9);

	printf("After  sort:");
	for (i = 0; i < 10; ++i)
		printf(" %2d", v[i]);
	putchar('\n');
	return 0;
}
