#include <stdio.h>
#include <math.h>
#include "callib.h"

#define MAXOP	100	/* max size of operand or operator */
#define NUMBER 	'0'	/* signal that a number was found. */
#define LETTER	'a'	/* signal that a variable with single-letter name */

/* reverse Polish calculator.
 * Write a routine ungets(s) that will push back on entire string onto the
 * input. Should ungets know that about buf and bufp, or should it just use
 * ungetch? ungets() 函数将使用 unget_ch() 函数来"回读"单个字符.
 */
int main()
{
	char s[MAXOP];
	double v[26] = {0.0};
	int type, index = 0;
	double op2;

	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(a_to_f(s));
				break;
			case LETTER:
				index = s[0] - 'a';
				push(v[index]);
				break;
			case '=':
				swap();
				pop();
				v[index] = duplicate_top();
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
			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push(fmod(pop(), op2));
				else
					printf("error: zero divisor\n");
				break;
			case '?':
				printf("The top element of stack is %g\n",duplicate_top());
				break;
			case '~':
				swap();
				break;
			case '#':
				clear_stack();
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command\n");
				break;
		}
	}
	return 0;
}
