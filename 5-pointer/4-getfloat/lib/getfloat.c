#include <stdio.h>

extern int is_space(const int c);
extern int is_digit(const int c);
extern int get_ch(void);
extern void unget_ch(const int c);

/* Write getfloat, the floating-point analog of getint. What type 
 * does getfloat return as its function value?
 */
int getfloat(float *pf)
{
	int c, sign;
	float power;

	while (is_space(c = get_ch()))	/* skip white space */
		;
	if (!is_digit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
		unget_ch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = get_ch();
	if (is_digit(c))
		for (*pf = 0.0; is_digit(c); c = get_ch())
			*pf = 10.0 * *pf + (c - '0');
	if (c == '.') {
		c = get_ch();	/* 跳过 小数点 '.' */
		for (power = 1.0; is_digit(c); c = get_ch()) {
			*pf = 10.0 * *pf + (c - '0');
			power *= 10;
		}
	}
	*pf = sign * *pf / power;
	if (c != EOF)
		unget_ch(c);
	return c;
}
