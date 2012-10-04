#include "cType.h"

/* aTof: convert string s to double */
double aTof(const char s[])
{
	double val, power;
	int i, sign;

	for (i = 0; isSpace(s[i]); ++i)
		;	/* skip white space */
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		++i;	/* skip sign */
	for (val = 0.0; isDigit(s[i]); ++i)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		++i;	/* skip decimal point */
	for (power = 1.0; isDigit(s[i]); ++i) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	return sign * val / power;
}
