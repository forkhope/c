#include <stdio.h>

extern void iToa(int n, char s[]);

/* 测试  iToa() 函数 */
int main()
{
	int i = 547855;
	char s[10];

	iToa(i, s);
	printf("convert %d to string is \"%s\"\n", i, s);
	i = -89703490;
	iToa(i, s);
	printf("convert %d to string is \"%s\"\n", i, s);
	return 0;
}
