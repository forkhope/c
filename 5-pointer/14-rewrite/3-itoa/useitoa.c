#include <stdio.h>

extern void itoa(int n, char *s);

/* 测试重写的 itoa() 函数 */
int main(void)
{
	int n;
	char a[20];

	n = 48019039;
	itoa(n, a);
	printf("%s\n", a);

	n = -490489;
	itoa(n, a);
	printf("%s\n", a);
	return 0;
}
