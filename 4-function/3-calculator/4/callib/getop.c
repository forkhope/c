#include <stdio.h>

extern int is_digit(const int c);
extern int is_loweralpha(const int c);
extern int get_ch(void);
extern void unget_ch(const int c);

int getop(char s[])
{
	int i, c, next;

	while ((s[0] = c = get_ch()) == ' ' || c == '\t')
		;	/* 我写代码时,还检查了回车,但是不应该检查回车,其是有效字符 */
	s[1] = '\0';
	if (is_loweralpha(c))	/* 判断是否是变量,变量名只有一个小写字母 */
		return 'a';
	if (!is_digit(c) && c != '.' && c != '-')
		return c;
	i = 0;
	if (c == '-') {	/* collect negative sign */
		if (!is_digit(next = get_ch()) && next != '.') {
			unget_ch(next);
			return c;
		}
		s[++i] = c = next;
	}
	if (is_digit(c))
		while (is_digit(s[++i] = c = get_ch()))
			;
	if (c == '.')	/* collect fraction part */
		while (is_digit(s[++i] = c = get_ch()))
			;
	s[i] = '\0';
	if (c != EOF)
		unget_ch(c);
	return '0';
}
