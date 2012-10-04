#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 100

int getword(char *, int);
struct key *binsearch(char *, struct key *, int);

struct key {
		char *word;
		int count;
} keytab[] = {
		{"break", 0},
		{"case", 0},
		{"char", 0},
		{"const", 0},
		{"continue", 0},
		{"default", 0},
		{"else", 0},
		{"for", 0},
		{"if", 0},
		{"int", 0},
		{"return", 0},
		{"struct", 0},
		{"unsigned", 0},
		{"void", 0},
		{"while", 0}
};
#define NKEYS (sizeof keytab / sizeof (keytab[0]))

/* count C keywords; pointer version */
int main(void)
{
	char word[MAXWORD];
	struct key *p;

	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			if ((p = binsearch(word, keytab, NKEYS)) != NULL)
				++p->count;
	for (p = keytab; p < keytab + NKEYS; ++p)
		if (p->count > 0)
			printf("%4d %s\n", p->count, p->word);
	return 0;
}

/* binsearch: find word in tab[0] ... tab[n-1] */
struct key *binsearch(char *word, struct key *tab, int n)
{
	int cond;
	struct key *low = &tab[0];
	struct key *high = &tab[n];
	struct key *mid;

	/* The most important changes is to adjust the algorithm to make sure
	   * it does not generate an illegal pointer or attempt to access an 
	   * element outside the array. The problem is that &tab[-1] and &tab[n]
	   * are both outside the limits of the array tab. The former is 
	   * strictly illegal, and it is illegal to dereference the latter. The
	   * language definition does guarantee, however, that pointer 
	   * arithmetic that involves the first element beyond the end of an
	   * array (that is, &tab[n]) will work correctly.
	   */
	while (low < high) {
		/* The computation of the middle element can no longer be simply
		 * mid = (low + high) / 2	// WRONG
		 * because the addition of pointers is illegal. Subtraction is 
		 * legal, however, so high - low is the number of elements, and thus
		 * mid = low + (high - low) / 2
		 * sets mid to the element halfway between low and high.
		 */
		mid = low + (high - low) / 2;
		if ((cond = strcmp(word, mid->word)) < 0)
			high = mid;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return NULL;
}

#define BUFSIZE	100			/* 缓冲区大小 */
static char buf[BUFSIZE];	/* 缓冲区空间 */
static char *bufp = buf;	/* 指向缓冲区中下一个可用的位置 */

int getch(void)		/* 返回一个字符,该字符可能是回读的字符 */
{
	return (bufp > buf) ? *--bufp : getchar();
}

void ungetch(const int c)	/* 回读字符 c 到缓冲区中 */
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

	while (isspace(c = getch())) 	/* 使用 isspace() 函数来作判断 */
		;
	if (c != EOF)
		*word++ = c;
	if (!isalpha(c)) {
		*word = '\0';
		return c;
	}
	for ( ; --lim > 0; ++word)	/* 使用 --lim 来控制输入的字符个数 */
		if (!isalnum(*word = getch())) {
			ungetch(*word);
			break;
		}
	*word = '\0';
	return word[0];
}
