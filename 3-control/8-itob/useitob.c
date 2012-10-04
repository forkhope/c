#include <stdio.h>

extern void itob(int n, char s[], unsigned int b);

/* 测试 itob() 函数 */
int main()
{
	int i = 36;
	char s[10];
	unsigned int base;

	base = 2;
	itob(i, s, base);
	printf("转换 %d 成二进制字符串为 %s\n", i, s);

	base = 8;
	itob(i, s, base);
	printf("转换 %d 成八进制字符串为 %s\n", i, s);

	base = 10;
	itob(i, s, base);
	printf("转换 %d 成十进制字符串为 %s\n", i, s);

	base = 16;
	itob(i, s, base);
	printf("转换 %d 成十六进制字符串为 %s\n", i, s);
	return 0;
}
