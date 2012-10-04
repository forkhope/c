#include <stdio.h>

extern void iToa(int n, char s[]);

/* 测试第二版的 iToa() 函数 */
int main()
{
	int i = 2147483647;
	char s[10];

	iToa(i, s);
	printf("convert %d to string is \"%s\"\n", i, s);

	i = -2147483647;
	iToa(i, s);
	printf("convert %d to string is \"%s\"\n", i, s);

	i = -2147483648;
	iToa(i, s);
	printf("convert %d to string is \"%s\"\n", i, s);
	return 0;
}
