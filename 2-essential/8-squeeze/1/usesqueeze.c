#include <stdio.h>

extern void squeeze(char s[], char c);

/* 测试 squeeze() 函数 */
int main()
{
	char a[] = "tian";
	char b[] = "atian";
	char c[] = "atianna";
	char d[] = "tianaaannaannnaaaaann";
	char e[] = "tianxiaaaaa";
	char ch = 'a';

	printf("Delete %c from %s is: ", ch, a);
	squeeze(a, ch);
	printf("%s\n", a);

	printf("Delete %c from %s is: ", ch, b);
	squeeze(b, ch);
	printf("%s\n", b);

	printf("Delete %c from %s is: ", ch, c);
	squeeze(c, ch);
	printf("%s\n", c);

	printf("Delete %c from %s is: ", ch, d);
	squeeze(d, ch);
	printf("%s\n", d);

	printf("Delete %c from %s is: ", ch, e);
	squeeze(e, ch);
	printf("%s\n", e);

	return 0;
}
