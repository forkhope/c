#include <stdio.h>
#include "getint.h"

#define SIZE	10	/* 数组长度 */

/* 测试 getint() 函数 */
int main(void)
{
	int n, array[SIZE] = {0};

	for (n = 0; n < SIZE && getint(&array[n]) != EOF; ++n)
		printf("array[%d] = %d\n", n , array[n]);
	return 0;
}
