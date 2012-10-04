#include "cType.h"

/* aToi: convert s to integer; version 3.
 * This one is slightly more general than the one in Chapter 2; it copes
 * with optional leading white space and an optional + or - sign.
 */
int aToi(const char s[])
{
	int i, sign, n;

	for (i = 0; isSpace(s[i]); ++i)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		++i;
	for (n = 0; isDigit(s[i]); ++i)
		n = n * 10 + (s[i] - '0');
	return n * sign;
}
