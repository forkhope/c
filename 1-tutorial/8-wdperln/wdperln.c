#include<stdio.h>

#define IN	1	/* inside a word */
#define OUT 0	/* outside a word */

/* Write a program that prints its input one word per line */
int main()
{
	int c, state;

	state = OUT;
	while ((c = getchar()) != EOF) {
		/* 可以换行的情况是:当前字符是空格,或者列表符,或者回车,且上一个字符
		 * 不是空格,不是列表符,不是回车.当第一个 if 判度为假时,表明当前字符
		 * 是空格,或者是列表符,或者回车,再判断 state 是否等于 IN,如果等于,
		 * 就表明上一个字符不是空格,不是列表符,不是回车.这时就可以换行输出.
		 */
		if (c != ' ' && c != '\t' && c != '\n') {
			putchar(c);
			state = IN;
		}
		else if (state == IN) {
			putchar('\n');
			state = OUT;
		}
	}
	return 0;
}
