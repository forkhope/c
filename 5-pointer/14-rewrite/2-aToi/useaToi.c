#include <stdio.h>

extern int aToi(const char *s);

/* 测试 aToi() 函数 */
int main(void)
{
	char a[] = "239094";
	char b[] = "-38948";
	int i;

	i = aToi(a);
	printf("i = %d\n", i);

	i = aToi(b);
	printf("i = %d\n", i);
	return 0;
}
