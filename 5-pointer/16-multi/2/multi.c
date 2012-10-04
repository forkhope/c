#include <stdio.h>

/* 二维数组的数组名的分析 */
int main(void)
{
	int array[3][4] = {
		{1, 2,  3,  4},
		{5, 6,  7,  8},
		{9, 10, 11, 12}
	};

	/* 一维数组的数组名是数组首元素的地址,二维数组的数组名是数组首元素
	 * 的地址的地址.例如,上面的二维数组array,其数组名array是一个指针,指向
	 * 一个包含4个整数的数组.则 array + 1 后指向的地址和原来的 array 之间
	 * 相差 4 * sizeof(int) 个字节;这里和一维数组的地址的地址加 1是一致的
	 * 其实,这也好理解.array = &array[0]指向二维数组的第1行, array + 1 =
	 * &array[1]指向二维数组的第2行,(*(array+1))[2]是第1行的第三个元素,如下
	 * 注意,不可写为*(array+1)[2],因为[]的优先级比*要高,(arry+1)[2]先结合,
	 * 这实际上相当于array+1+2 = &array[3],然后才和*结合,获取到array[3]的
	 * 地址,这已经超出了数组array的范围,发生越界的现象;写成(*(array+1))[2]
	 * 则*(array+1)先结合,获取到array[1]的地址,即二维数组的第2行的首地址,
	 * 然后才和[2]结合,即为array[1][2] = 7,下面打印出来的就是 7.
	 * 由于二维数组名相当于该数组首元素的地址的地址,所以要获取具体的某个
	 * 元素时,就需要进行两次解引用操作.上面的*(array+1)是第一个解引用,与
	 * [2]结合是第二次解引用,之后才正确地指向元素array[1][2].这是关键点.
	 */
	printf("(*(array+1))[2] = %d\n", (*(array+1))[2]);
	return 0;
}
