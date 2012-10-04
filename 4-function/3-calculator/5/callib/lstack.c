/* 实现一个简单的栈 */
#include <stdio.h>

#define MAXVAL	100		/* 栈空间的大小 */
int sp = 0;				/* 指向栈中下一个可用位置 */
double val[MAXVAL];		/* 栈空间,保存浮点操作数 */

/* push: push f onto value stack */
void push(const double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* print_top: print the top elements of the stack with popping */
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
	if (sp > 2) {
		double item1 = pop();
		double item2 = pop();
		push(item1);
		push(item2);
	}
	else
		printf("error: only zero or one element in the stack\n");
}

/* clear_stack: clear the stack */
void clear_stack(void)
{
	sp = 0;
}
