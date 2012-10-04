#include <string.h>

/* 使用指针代替数组下标,重写 itoa() 函数 */
void itoa(int n, char *s)
{
	int sign;
	char *p;
	void reverse(char *s);

	if ((sign = n) < 0)
		n = -n;
	p = s;
	do {
		*p++ = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		*p++ = '-';
	*p = '\0';
	reverse(s);
}

void reverse(char *s)
{
	int c;
	char *p;

	for (p = s + strlen(s) - 1; s < p; ++s, --p) {
		c = *s;
		*s = *p;
		*p = c;
	}
}
