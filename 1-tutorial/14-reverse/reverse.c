#include<stdio.h>
#define MAXLINE	1000	/* maximum input line length */

int getLine(char line[], int maxline);
void reverse(char s[]);

/* Write a function reverse(s) that reverses the character string s. Use it
 * to write a program that reverses its input a line at a time.
 */
int main()
{
	char s[MAXLINE];
	while (getLine(s, MAXLINE) > 0) {
		reverse(s);
		printf("%s\n", s);
	}
	return 0;
}

int getLine(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	s[i] = '\0';
	return i;
}

void reverse(char s[])
{
	char ch;
	int i, j;

	for (i = 0; s[i] != '\0'; ++i)
		;
	--i;
	for (j = 0; j < i; ++j, --i) {
		ch = s[j];
		s[j] = s[i];
		s[i] = ch;
	}
}
