extern int is_space(const int c);
extern int is_digit(const int c);

/* a_to_f: convert string s to double */
double a_to_f(const char s[])
{
	int i, sign;
	double val, power;

	for (i = 0; is_space(s[i]); ++i)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '-' || s[i] == '+')
		++i;
	for (val = 0.0; is_digit(s[i]); ++i)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		++i;
	for (power = 1.0; is_digit(s[i]); ++i) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	return sign * val / power;
}
