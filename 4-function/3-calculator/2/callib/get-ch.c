#include <stdio.h>
#define BUFSIZE	100		/* buffer size */
char buf[BUFSIZE];		/* buffer for unget_ch() */
int bufp = 0;			/* next free position in buf */

int get_ch(void)			/* get a (possibly pushed-back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* 当函数参数是char 型时,可以选择用int 型来替代,这样会好一点 */
void unget_ch(int c)	/* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("unget_ch: too many characters\n");
	else
		buf[bufp++] = c;
}
