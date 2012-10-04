#include <stdio.h>

#define BUFSIZE	100			/* 缓冲区大小 */
static char buf[BUFSIZE];	/* 缓冲区数组空间 */
static char *bufp = buf;	/* 指向缓冲区中下一个可用位置 */

int getch(void)		/* 读取一个字符,该字符可能是回读的字符 */
{
	return (bufp > buf) ? *--bufp : getchar();
}

void ungetch(const int c)	/* 回读一个字符到缓冲区数组中 */
{
	if (bufp < buf + BUFSIZE)
		*bufp++ = c;
	else
		printf("ungetch: too many characters\n");
}
