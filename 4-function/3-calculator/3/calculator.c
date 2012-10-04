#include <stdio.h>
#include <math.h>
#include "callib.h"

#define MAXOP	100	/* max size of operand or operator */
#define NUMBER 	'0'	/* signal that a number was found. */
#define LETTER	'a'	/* signal that a variable with single-letter name */

/* reverse Polish calculator.
 * Add commands for handling variables. (It's easy to provide twenty-six
 * variables with single-letter names). Add a variable for the most
 * recently printed value.
 */
int main()
{
	char s[MAXOP];
	double v[26] = {0.0};	/* 表示 26 个单字母的可用变量 */
	int type, index = 0;
	double last_value;
	double op2;

	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(a_to_f(s));
				break;
			case LETTER: 	/* 遇到a-z中单个字母,即当作变量处理 */
				index = s[0] - 'a';	/* 保存当前字母在数组中的下标 */
				push(v[index]);	/* 变量值压栈,若变量没有赋值,默认为0.0 */
				break;
			/* 使用类似 a 8 = 的方式为将变量a 赋值为8,则遇到 = 号时,
			 * 已经将变量值和新的值压栈.
			 */
			case '=':	
				swap(); /* 交换栈顶两个元素的值,让新的变量值沉入第二位 */
				pop();	/* 弹出栈顶的旧变量值 */
				v[index] = duplicate_top();	/* 保存新的变量值到数组中 */
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
				last_value = pop();
				printf("\t%.8g\n", last_value);
				break;
			default:
				printf("error: unknown command\n");
				break;
		}
	}
	return 0;

}
