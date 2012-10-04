#include <stdio.h>
#include <ctype.h>
#include "getch.h"

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
