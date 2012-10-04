#include <stdio.h>

extern int is_space(const int c);
extern int is_digit(const int c);
/* We have also used get_ch and unget_ch so the one extra character that
 * must be read can be pushed back onto the input.
 */
extern int get_ch(void);
extern void unget_ch(const int c);

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
	int c, sign;

	while (is_space(c = get_ch()))
		;
	if (!is_digit(c) && c != EOF && c != '+' && c != '-') {
		unget_ch(c); /* it is not a number */
		return 0;	/* getint() 函数返回 0,表示没有获取到有效数字 */
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = get_ch();
	for (*pn = 0; is_digit(c); c = get_ch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF) 
		unget_ch(c);
	return c;
}
