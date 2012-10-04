#include <stdio.h>

extern int is_digit(int c);
extern int is_loweralpha(int c);
extern int get_ch(void);
extern void unget_ch(int c);

/* getop: get next characer or numeric operand */
int getop(char s[])
{
	int c, i, next;

	while ((s[0] = c = get_ch()) == ' ' || c == '\t')
		;	/* 不检查回车 */
	s[1] = '\0';
	if (is_loweralpha(c))	/* 遇到 a-z 中的单个字母,即看作变量 */
		return 'a';
	if (!is_digit(c) && c != '.' && c != '-')
		return c;		/* not a number */
	i = 0;
	next = get_ch();	/* 取出下一个字符,用于判断是否存在负号 */
	if (c == '-')		/* collect negative sign */
		if (!is_digit(next) && next != '.') {
			unget_ch(next);
			return c;
		}
	c = next;
	while (is_digit(s[++i] = c))
		c = get_ch();
	if (c == '.')		/* collect fraction part */
		while (is_digit(s[++i] = c = get_ch()))
			;
	s[i] = '\0';		/* 我在写代码时,忘记了写这一句 */
	if (c != EOF)
		unget_ch(c);
	return '0';		/* 表示获取到操作数 */
}
