#include <stdio.h>
#include <ctype.h>

#define BUFSIZE	100			/* 缓冲区大小 */
static char buf[BUFSIZE];	/* 缓冲区空间 */
static char *bufp = buf;	/* 指向缓冲区中下一个可用的位置 */

int getch(void)	/* 返回一个字符,该字符可能是回读的字符 */
{
	return (bufp > buf) ? *--bufp : getchar();
}

void ungetch(const int c)	/* 回读一个字符到缓冲区中 */
{
	if (bufp < buf + BUFSIZE)
		*bufp++ = c;
	else
		printf("ungetch: too many characters\n");
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
	int c;

	while ((c = getch()) == ' ' || c == '\t')
		;
	if (c != EOF)
		*word++ = c;
	if (!isalnum(c) && c != '#') {
		*word = '\0';
		return c;
	}
	for ( ; --lim > 0; ++word)
		if (!isalnum(*word = getch())) {
			ungetch(*word);
			break;
		}
	*word = '\0';
	return word[0];
}
