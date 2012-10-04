/* 实现一个简单的栈,包括对对栈的基本操作 : 压栈、出栈等 */
#include <stdio.h>

#define MAXVAL	100		/* 栈空间大小 */
int sp = 0;				/* 指向栈顶的上一个位置 */
double val[MAXVAL];		/* 栈空间, 该栈用于保存浮点操作数 */

/* Add the commands to print the top elements of the stack without 
 * popping, to duplicate it, and to swap the top two elements. 
 * Add a command to clear the stack.
 */

/* push: push f onto value stack */
void push(const double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)		/* 当参数列表为空时,记得使用 void 来显式限定 */
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* print the top elements of the stack without popping */
void print_top(void)
{
	if (sp > 0)	/* 我写的时候,都忘记对栈顶下标的值进行检查,很差的习惯 */
		printf("\t%.8g\n", val[sp-1]);
	else
		printf("error: stack empty\n");
}

/* duplicate the top elements */
double duplicate_top(void)
{
	if (sp > 0)	/* 千万不要了进行错误检查! */
		return val[sp-1];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* swap the top two elements */
void swap(void)
{
	/* pop() 和 push() 函数都带有错误检查,所以这里不需要再检查 */
	double item1 = pop();
	double item2 = pop();

	push(item1);
	push(item2);
}

/* clear the stack */
void clear_stack(void)
{
	sp = 0;
}
