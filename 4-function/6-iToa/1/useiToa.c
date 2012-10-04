#include <stdio.h>

extern void iToa(int n, char s[]);

/* 测试采用递归实现的 iToa() 函数 */
int main(void)
{
	int i;
	char s[10] = {0};

	i = -48982;
	iToa(i, s);
	printf("%s\n", s);

	i = 34842;
	iToa(i, s);
	printf("%s\n", s);
	return 0;
}
