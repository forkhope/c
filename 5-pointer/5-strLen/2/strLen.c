#include <stdio.h>

int strLen(char *s);

int main(void)
{
	printf("The length of \"%s\" is %d\n",
			"tianxia", strLen("tianxia"));
	return 0;
}

/* Pointer subtraction is also valid: if p and q point to elements of the
 * same array, and p < q, then q - p + 1 is the number of elements from p
 * to q inclusive. This fact can be used to write yet another version of
 * strLen. strLen: return length of string s*/
int strLen(char *s)
{
	char *p = s;

	while (*p != '\0')
		++p;
	return p - s;
}
