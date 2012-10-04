#include <ctype.h>

int aToi(const char *s)
{
	int n, sign;

	while (isspace(*s))
		++s;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '-' || *s == '+')
		++s;
	for (n = 0; isdigit(*s); ++s)
		n = n * 10 + (*s - '0');
	return sign * n;
}
