#include <stdio.h>
#define BUFSIZE 100

char buf[BUFSIZE];		/* buffer for ungetch */
int bufp = 0;			/* next free position in buf */

/* getCh() 函数优先从 buf[] 数组中读取一个字符,如果 buf[] 数组为空,则调用
 * getchar() 函数接收用户输入.而buf[]数组有 ungetCh() 函数来填充,如下:
 */
int getCh(void)			/* get a (possibly pushed-back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetCh(int c)		/* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetCh: too many characters\n");
	else
		buf[bufp++] = c;
}
