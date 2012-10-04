#include <string.h>

/* Adapt the ideas of printd to write a recursive version of itoa; that 
 * is, convert an integer into a string by calling a recursive routine.
 */
void iToa(int n, char s[])
{
	static int i = 0; /* 为了递归调用自身时,i不会被重复初始化,且值不变 */
	static int sign = 0;
	void reverse(char s[]);

	if (n < 0) {
		sign = n;
		n = -n;
	}
	s[i++] = n % 10 + '0';
	if (n / 10)
		iToa(n / 10, s);
	else {
		if (sign < 0) {
			s[i++] = '-';
			sign = 0;
		}
		s[i] = '\0';
		i = 0;
		reverse(s);
	}
}

void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
