#include "cType.h"

/* Extend atof() to handle scientific notation of the form 123.45e-6 where
 * a floating-point number may be followed by e or E and an optionally
 * signed expoent.
 */
double aTof(const char s[])
{
	double val, power;
	int i, sign;
	int ex_sign, exponent;

	/* 处理自然记数法的底数部分 */
	for (i = 0; isSpace(s[i]); ++i)
		; 		/* skip white space */
	sign = (s[i] == '-') ? -1 : 1;	/* 底数本身的符号 */
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

	/* 下面处理自然记数法的指数部分 */
	if (s[i] == 'e' || s[i] == 'E')
		++i;	/* skip 'e' or 'E' */
	ex_sign = (s[i] == '-') ? -1 : 1;	/* 指数的符号 */
	if (s[i] == '+' || s[i] == '-')
		++i;
	/* 获取指数部分的整数值 */
	for (exponent = 0; isDigit(s[i]); ++i)
			exponent = 10 * exponent + (s[i] - '0');
	/* 下面for循环里的语句原本是这样写: (ex_sign)?(power/=10):(power*=10)
	 * 这条语句有错,犯了我以前犯过的一个错误.在 C语言中,非0为真,0为假;当
	 * 指数为负时,ex_sign=-1;指数为真时,ex_sign=1; 但是不管ex_sign是等于1
	 * 还是等于 -1, (ex_sign) 的判断结果都成为真.而原本语句是希望当ex_sign
	 * 为假时,执行 (power*=10),当ex_sign为真时,执行 (power/=10);这条语句的
	 * 执行结果就和预期不符.写成下面的形式,就可以消除这个错误.
	 * 在写判断语句时,尽量还是写明判断条件,可以避免类似的细节错误.
	 */
	for (; exponent; --exponent)
		(ex_sign == -1) ? (power *= 10) : (power /= 10);
	return sign * val / power;
}
