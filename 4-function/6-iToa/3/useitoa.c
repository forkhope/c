#include <stdio.h>

extern void itoa(int n, char s[]);

int main(void)
{
	int i;
	char s[10] = {0};

	i = 353298;
	itoa(i, s);
	printf("%s\n", s);
	
	i = -84539;
	itoa(i, s);
	printf("%s\n", s);
	return 0;
}
