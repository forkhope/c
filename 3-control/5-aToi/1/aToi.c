#include <ctype.h>

/* aToi: convert s to integer; version 2.
 * This one is slightly more general than the one in Chapter 2; it copes
 * with optional leading white space and an optional + or - sign.
 */
int aToi(const char s[])
{
	int i, n, sign;

	for (i = 0; isspace(s[i]); ++i) /* skip white space */
		;
	/* 由于正号可能会被省略,所以下面是判断是否有负号. */
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')	/* skip sign */
		++i;
	for (n = 0; isdigit(s[i]); ++i)
		n = 10 * n + (s[i] - '0');
	return sign * n;
}
