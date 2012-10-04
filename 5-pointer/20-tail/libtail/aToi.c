#include "cType.h"

/* aToi: convert string s to int */
int aToi(const char *s)
{
	int n, sign;

	while (is_space(*s))
		++s;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '+' || *s == '-')
		++s;
	for (n = 0; is_digit(*s); ++s)
		n = 10 * n + (*s - '0');
	return sign * n;
}
