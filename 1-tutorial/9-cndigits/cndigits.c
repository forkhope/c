#include<stdio.h>

/* count digits, white space(blank, tab, newline), others */
int main()
{
	int c, i, nwhite, nother;
	int ndigit[10];

	nwhite = nother = 0;
	for (i = 0; i < 10; ++i)
		ndigit[i] = 0;

	while ((c = getchar()) != EOF) {
		/* getchar() 函数返回的整型值是字符的ASCII码值,而单引号括起来的字符
		 * 常量正好也等于字符的ASCII码值,所以可以将 getchar() 函数的返回值
		 * 和字符常量进行比较,来判断具体是哪个字符.0到9的ASCII码值是48到57.
		 */
		if (c >= '0' && c <= '9')	// >= 的优先级大于 &&,不用加括号
			++ndigit[c-'0'];		// c - '0' 的结果在 0 到 9 之间.
		else if (c == ' ' || c == '\t' || c == '\n')
			++nwhite;
		else 
			++nother;
	}
	printf("digits =");
	for (i = 0; i < 10; ++i)
		printf(" %d", ndigit[i]);
	printf(", white spaces = %d, others = %d\n", nwhite, nother);
	return 0;
}
