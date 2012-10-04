#include "cType.h"

/* aTof: convert string s to double */
double aTof(const char *s)
{
	int sign;
	double val, power;

	while (is_space(*s))
		++s;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '+' || *s == '-')
		++s;
	for (val = 0.0; is_digit(*s); ++s)
		val = 10.0 * val + (*s - '0');
	if (*s == '.')
		++s;
	for (power = 1.0; is_digit(*s); ++s) {
		val = 10.0 * val + (*s - '0');
		power *= 10.0;
	}
	return sign * val / power;
}
