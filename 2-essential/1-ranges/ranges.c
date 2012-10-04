#include <stdio.h>
#include <limits.h>

int power(int x, int y);

/* Write a program to determine the ranges of char, short, int, and long
 * variables, both signed and unsigned, by printing appropriate values from
 * standard headers and by direct computation. Harder if you compute them:
 * determine the ranges of the various floating-point types.
 */
int main()
{
	printf("-------使用定义在 <limits.h> 中的宏来获得取值范围--------\n");
	printf("Size of char %d\n", CHAR_BIT);
	printf("Size of char max %d\n", CHAR_MAX);
	printf("Size of char min %d\n", CHAR_MIN);
	printf("Size of int max %d\n", INT_MAX);
	printf("Size of int min %d\n", INT_MIN);
	printf("Size of short max %d\n", SHRT_MAX);
	printf("Size of short min %d\n", SHRT_MIN);
	printf("Size of long max %ld\n", LONG_MAX);
	printf("Size of long min %ld\n", LONG_MIN);
	printf("Max of unsigned char %u\n", UCHAR_MAX);
	printf("Max of unsigned int %u\n", UINT_MAX);
	printf("Max of unsigned short %u\n", USHRT_MAX);
	printf("Max of unsigned long %lu\n", ULONG_MAX);

	/* 通过计算得到数据类型的取值范围.首先使用sizeof操作符得到数据类型所占的
	 * 字节数,记住要乘以8,因为sizeof(char)的值是 1,表示char型占一个字节,乘以
	 * 8,才是char型所占的实际位数,又因为一般char是表示signed char,所以最高位
	 * 被占用来表示正负,剩下的低7位用来表示数值,所以要减去1,然后用power(2,7)
	 * 计算出2的7次方的值,所得值再减去 1,就是char型的最大值了,其最小值是最大
	 * 值的相反数减去1.这里,最小值的绝对值总是比最大值的绝对值多 1.
	 */
	printf("-------通过计算得到数据类型的取值范围------------\n");
	int value;
	long bigvalue;
	value = power(2, sizeof(char) * 8 - 1) - 1;
	printf("Size of char max %d\n", value);
	printf("Size of char min %d\n", -value - 1);
	value = power(2, sizeof(int) * 8 - 1) - 1;
	printf("Size of int max %d\n", value);
	printf("Size of int min %d\n", -value - 1);
	value = power(2, sizeof(short) * 8 - 1) - 1;
	printf("Size of short max %d\n", value);
	printf("Size of short min %d\n", -value - 1);
	bigvalue = power(2, sizeof(long) * 8 - 1) - 1;
	printf("Size of long max %ld\n", bigvalue);
	printf("Size of long min %ld\n", -bigvalue - 1);
	unsigned int uvalue;
	uvalue = power(2, sizeof(char) * 8) - 1;
	printf("Max of unsigned char %u\n", uvalue);
	uvalue = power(2, sizeof(int) * 8) - 1;
	printf("Max of unsigned int %u\n", uvalue);
	uvalue = power(2, sizeof(short) * 8) - 1;
	printf("Max of unsigned short %u\n", uvalue);
	unsigned long ubigvalue = power(2, sizeof(long) * 8) - 1;
	printf("Max of unsigned long %lu\n", ubigvalue);
	return 0;
}

int power(int base, int n)
{
	int i, p;

	p = 1;
	for (i = 1; i <= n; ++i)
		p *= base;
	return p;
}
