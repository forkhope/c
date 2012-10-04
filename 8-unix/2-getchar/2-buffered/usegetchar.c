#include <stdio.h>

extern int getChar(void);

int main(void)
{
	int c;

	while ((c = getchar()) != EOF)
		putchar(c);
	return 0;
}
