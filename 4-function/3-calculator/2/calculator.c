#include <stdio.h>
#include <math.h>
#include "callib.h"

#define MAXOP	100		/* max size of operand or operator */
#define NUMBER 	'0'		/* signal that a number was found. */

/* reverse Polish calculator 
 * Given the basic framework, it's straightforward to extend the calculator
 * Add the modulus(%) operator and provitions for negative numbers.
 */
int main()
{
	char s[MAXOP];
	double op2;
	int type;

	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
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
			case '/':		/* 下面进行除法运算时,记得判断除数是否为 0 */
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '%':		/* 求模运算要求除数不能是 0 */
				op2 = pop();
				/* 运算符 % 只能用于两个整数值之间的求模,浮点数求模需要
				 * <math.h> 函数库中的 fmod() 函数,如下所示:
				 */
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
				clear_stack();	/* 清空栈 */
				break;
			case '\n':
				print_top();	/* 打印栈顶元素 */
				pop();			/* 弹出栈顶元素 */
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}
