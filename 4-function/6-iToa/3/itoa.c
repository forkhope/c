/* Adapt the ideas of printd to write a recursive version of itoa; that
 * is, convert an integer into a string by calling a recursive routine.
 */
#include <string.h>

void backitoa(int n, char s[]);
void reverse(char s[]);

void itoa(int n, char s[])
{
	backitoa(n, s);
	reverse(s);
}

void backitoa(int n, char s[])
{
	if (n < 0) {
		backitoa(-n, s);
		int i = strlen(s);
		*(s+i) = '-';
		*(s+i+1) = '\0';
		return ;
	}
	*s = n % 10 + '0';
	if (n / 10)
		backitoa(n / 10, s+1);
	else
		*(s+1) = '\0';
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
