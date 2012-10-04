/* 实现一个简单的栈，包括栈的基本操作 */
#include <stdio.h>

#define MAXVAL	100		/* 栈空间大小 */
int sp = 0;				/* 指向栈空间下一个可用的位置 */
double val[MAXVAL];		/* 栈空间，该栈用于保存浮点操作数 */

/* push: push f onto value stack */
void push(const double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack*/
double pop(void)		/* 记得使用 void 来显示限定空参数列表 */
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;		/* 我写代码时,忘了写这一句,严重错误 */
	}
}

/* print_top: print the top elements of the stack without popping */
void print_top(void)
{
	if (sp > 0)
		printf("\t%.8g\n", val[sp-1]);
	else
		printf("error: stack empty\n");
}

/* duplicate_top: duplicate the top elements */
double duplicate_top(void)
{
	if (sp > 0)
		return val[sp-1];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* swap: swap the top two elements */
void swap(void)
{
	double item1 = pop();
	double item2 = pop();

	push(item1);
	push(item2);
}

/* clear_stack: clear the stack */
void clear_stack(void)
{
	sp = 0;
}
