#include <stdio.h>
#include "lstack.h"

#define MAXOP	100		/* max size of operand or operator. */
#define NUMBER	'0'		/* signal that a number was found. */

extern int getop(char s[]);
extern double aTof(const char s[]);

/* reverse Polish calculator */
int main()
{
	int type;
	double op2;
	char s[MAXOP];

	/* 下面使用 getop() 函数,而不使用 getLine() 函数的原因是: getLine() 函数
	 * 仅是获取一行输入,而 getop() 函数获取输入的同时,会根据不同的输入,返回
	 * 不同的值,例如当输入的是数字时,会返回 '0',下面使用 NUMBER 宏来表示它
	 */
	while ((type = getop(s)) != EOF) {
		switch (type) {		/* getop() 函数会返回获取的字符类型 */
			case NUMBER:	/* 当获取到数字时, getop()函数返回 '0' */
				push(aTof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}
