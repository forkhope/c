#include <stdio.h>

extern void squeeze(char s1[], const char s2[]);

int main()
{
	char s1[] = "tianxia";
	const char s2[] = "ai";

	printf("[%s] - ", s1);
	squeeze(s1, s2);
	printf("[%s] = [%s]\n", s2, s1);
	return 0;
}
