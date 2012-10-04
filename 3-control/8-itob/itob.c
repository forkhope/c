#include <string.h>
#include <stdlib.h>

/* reverse: reverse string s in place */
void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i < j; ++i, --j) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
/* Write the function itob(n, s, b) that converts the integer n into a base
 * b character represenation in the string s. In particular, itob(n, s, 16)
 * formats s as a hexadecimal integer in s.
 */
void itob(int n, char s[], unsigned int b)
{
	const char alnums[] = "0123456789ABCDEF";
	int i, sign;

	sign = n;
	i = 0;
	do {
		/* 由于ASCII表中, 0-9 和 A-F 之间并不是连续的,按照一般的方法就需要
		 * 进行判断,如果模大于9,则s[i++]=abs(n % 16) + 'A',如果模小于9,则
		 * s[i++]=abs(n % 16) + '0'; 但是使用下面的写法则更自然一些.
		 */
		s[i++] = alnums[abs(n % b)];
	} while (n /= b);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}
