#include <stdio.h>

extern int itoa(int n, char s[]);

/* 测试 itoa() 函数 */
int main(void)
{
	int i;
	char s[10] = {0};

	i = -48942;
	itoa(i, s);
	printf("%s\n", s);

	i = 44898293;
	itoa(i, s);
	printf("%s\n", s);
	return 0;
}
