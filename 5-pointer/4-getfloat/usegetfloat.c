#include <stdio.h>
#include "getfloat.h"

#define SIZE	10	/* 数组长度 */

/* 测试 getint() 函数 */
int main(void)
{
	int n;
	float array[SIZE] = {0.0};

	for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; ++n)
		printf("array[%d] = %g\n", n , array[n]);
	return 0;
}
