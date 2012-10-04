#include <string.h>
#include <stdlib.h>		/* abs() 函数 */

/* 使用指针代替数组下标,重写 itob() 函数 */
void itob(unsigned int n, char *s, const int base)
{
	const char alnums[] = "0123456789ABCDEF";
	char *p;
	void reverse(char *s);

	p = s;
	do {
		*p++ = alnums[abs(n % base)];
	} while ((n /= base) > 0);
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
