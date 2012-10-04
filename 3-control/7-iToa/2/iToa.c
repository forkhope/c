#include <string.h>
#include <stdlib.h>		/* abs()函数在该头文件中声明 */

/* reverse: reverse string s in place */
void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i < j; ++i, --j) {
		c = s[j];
		s[j] = s[i];
		s[i] = c;
	}
}
/* In a two's complement number represenation, our version of itoa does not
 * handle the largest negative number, that is, the value of n equal to 
 * -(2 to the power (wordsize - 1)). Explain why not. Modify it to print 
 * that value correctly, regardless of the machine on which it runs.
 * 目录1/中iToa.c程序有缺陷,原因是程序中有如下的代码:
 * if ((sign = n) < 0)
 *     n = -n;
 * 当 n 等于机器上最大的负数时,例如32位机器上的最大负数-2147483648,则该负数
 * 的相反数是2147483648.但是32位机器int型的最大值是2147483647,即执行 n = -n
 * 会发生上溢,2147483648 上溢的结果是 -2147483648,即执行 n = -n 后,n 的值并
 * 没有改变.然后,程序的do-while循环会先执行 s[i++]=n%10+'0'= -8+'0'=40,然后
 * 判断 (n /= 10) >0 为加,跳出循环,即循环只执行了一次.由于40在ASCII表中对应
 * 左括号'(',所以转换后的字符串是"-(",这个结果和实际执行结果是一致的.
 * 改正这个问题的方法是,修改 do-while 循环里的实现语句,如下所示:
 */
void iToa(int n, char s[])
{
	int i, sign;

	sign = n;
	i = 0;
	do {
		s[i++] = abs(n % 10) + '0'; /* abs(n)函数返回n的绝对值.这是关键 */
	} while (n /= 10); /* 即使 n 是负数,判断的结果依然是真,继续执行 */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}
