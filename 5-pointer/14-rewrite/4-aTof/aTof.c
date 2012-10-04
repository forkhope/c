#include <ctype.h>

/* 使用指针代替数组下标,重写 aTof() 函数 */
double aTof(const char *s)
{
	int sign;
	int ex_sign, exponent;
	double val, power;

	/* 处理自然记数法的底数部分 */
	while (isspace(*s))
		++s;
	sign = (*s == '-') ? -1 : 1;	/* 底数本身的符号 */
	if (*s == '+' || *s == '-')
		++s;
	for (val = 0.0; isdigit(*s); ++s)
		val = 10.0 * val + (*s - '0');
	if (*s == '.')
		++s;
	for (power = 1.0; isdigit(*s); ++s) {
		val = 10.0 * val + (*s - '0');
		power *= 10;
	}

	/* 下面处理自然记数法的指数部分 */
	if (*s == 'e' || *s == 'E')
		++s;
	ex_sign = (*s == '-') ? -1 : 1;	/* 指数的符号 */
	if (*s == '+' || *s == '-')
		++s;
	/* 获取指数部分的整数值 */
	for (exponent = 0; isdigit(*s); ++s)
		exponent = 10 * exponent + (*s - '0');
	for ( ; exponent; --exponent)
		(ex_sign == -1) ? (power *= 10) : (power /= 10);
	return sign * val / power;
}
