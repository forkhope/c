#include <stdio.h>
#include <ctype.h>

static int getch(void);
static void ungetch(const int c);

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
	int c;

	while (isspace(c = getch()))
		;
	if (c != EOF)
		*word++ = c;
	if (!isalpha(c)) {
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

#define BUFSIZE	100
static char buf[BUFSIZE];
static char *bufp = buf;

static int getch(void)
{
	return (bufp > buf) ? *--bufp : getchar();
}

static void ungetch(const int c)
{
	if (bufp < buf + BUFSIZE)
		*bufp++ = c;
	else
		printf("ungetch: too many characters\n");
}
