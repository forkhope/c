#include <stdio.h>

extern int binsearch(int x, int v[], int n);

/* 测试 binsearch() 函数 */
int main()
{
	int v[] = {2, 3, 5, 8, 9, 12, 14, 32, 44, 50}; /* 10 个整数 */
	int x;
	int position;

	int i;
	printf("输入v[]的所有元素如下:\n");
	/* 注意下面的for循环中printf()函数的写法.我以前写的是如下的形式:
     * for (i = 0; i < 10; ++i)
	 *     printf("%d ", v[i]);
	 * printf("\n");
	 * 而 K&R 的书中第49页提到了下面的printf()函数的写法.这样写需要一点技巧,
	 * 但显得更紧凑.当然,每次都要判断一下,是否效率会变低?这需要研究才知道.
	 */
	for (i = 0; i < 10; ++i)
		printf("%d%c", v[i], (i == 9) ? '\n' : ' ');

	x = 14;
	position = binsearch(x, v, 10);
	printf("在v[]中, %d 是第 %d 个元素(从0开始数)\n", x, position);
	
	x = 66;
	position = binsearch(x, v, 10);
	(position == -1) ? printf("在v[]中,没有一个元素的值等于 %d\n", x)
		: printf("在v[]中, %d 是第 %d 个元素(从0开始数)\n", x, position);
	return 0;
}
