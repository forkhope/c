#include <stdio.h>

extern unsigned getbits(unsigned x, int p, int n);

/* 测试 getbits() 函数 */
int main()
{
	unsigned i;
	
	/* 24 = 00011000, 从第4位起向右取4个位,并返回这4个位,可以看到从右往左,
	 * 由0开始数,第4位是最左边的那个1,从那个1起向右取4个位,是1100,等于12.
	 * 下面的printf语句输出的结果正是: getbits(24, 4, 4) = 12.
	 */
	i = getbits(24, 4, 4);
	printf("getbits(24, 4, 4) = %u\n", i);
	return 0;
}
