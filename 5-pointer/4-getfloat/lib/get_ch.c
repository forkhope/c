#include <stdio.h>

#define BUFSIZE	100		/* 缓冲区大小 */
char buf[BUFSIZE];		/* 缓冲区 */
int bufp = 0;			/* 指向缓冲区下一个可用的位置 */

int get_ch(void)			/* get a (possibly pushed-back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void unget_ch(const int c)	/* push character back on input */
{
	if (bufp < BUFSIZE)
		buf[bufp++] = c;
	else
		printf("unget_ch: too many characters\n");
}
