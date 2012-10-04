#include <stdio.h>		/* EOF 在其中定义 */

extern int get_ch(void);
extern void unget_ch(int c);
extern int isDigit(const int c);

/* getop: get next character or numeric operand */
int getop(char s[])
{
	int c, i, next;

	while ((s[0] = c = get_ch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isDigit(c) && c != '.' && c != '-')
		return c;		/* not a number */
	i = 0;
	next = get_ch();	/* 取出下一个字符,用于判断是否存在负号 */
	if (c == '-') 		/* collect negative sign */
		if (!isDigit(next) && next != '.') { 
			/* 如果没有后面的回读,则在处理 5 6 -\n 这样的式子会出错,因为'-'
			 * 后面是回车,且回车符已被读出赋给了next;而下面直接返回了'-',则
			 * 回车符被丢弃,没有得到处理.所以输入 5 6 - 后,不会立刻输出结果
			 * 需要再次输入回车才会输出结果;这和用户预期不符.
			 * 可以使用 回读 来解决这个问题,将多读的回车符重新"放回"缓冲区,
			 * 下次再读出来进行处理,就不会丢弃额外的字符. 这就是回读的好处
			 */
			unget_ch(next); /* 由于多读出了 next,所以返回前,要回读 */
			return c;
		}
	c = next;
	while (isDigit(s[++i] = c))
		c = get_ch();
	if (c == '.')		/* collect fraction part */
		while (isDigit(s[++i] = c = get_ch()))
			;
	s[i] = '\0';
	if (c != EOF)
		unget_ch(c);
	return '0';
}
