#include <stdio.h>

int strLen(char *s);

int main(void)
{
	printf("The length of \"%s\" is %d\n", 
			"tianxia", strLen("tianxia"));
	return 0;
}

/* strLen: return length of string s */
int strLen(char *s)
{
	int n;

	for (n = 0; *s != '\0'; ++s)
		++n;
	return n;
}
