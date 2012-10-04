#include <stdio.h>

extern void expand(const char s1[], char s2[]);

/* 测试 expand() 函数 */
int main()
{
	const char *s1[] = {"a-z","-a-z","a-z-","-1-9-","a-z0-9","a-b-c",NULL};
	char s2[1000];
	int i = 0;

	while (s1[i]) {
		expand(s1[i], s2);
		printf("Unexpanded: %s\n", s1[i]);
		printf("Expanded  : %s\n", s2);
		++i;
	}
	return 0;
}
