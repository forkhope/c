/* 实现一个简单的栈,并包含对栈的基本操作 */
#include <stdio.h>

#define MAXVAL	100		/* 栈空间大小 */
int	sp = 0;				/*指向栈下一个可用的空位置 */ 
double val[MAXVAL];		/* 栈空间, 该栈用于保存浮点操作数 */

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)	/* 当参数列表为空时,不要忘记使用 void 来显示限定 */
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: empty stack\n");
		return 0.0;	/* 我在写代码时,忘记了写这一句,编译出错 */
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
		return 0.0;	/* 写函数时,要注意返回值 */
	}
}

/* swap: swap the top two elements */
void swap(void)
{
	double item1 = pop();	/* 注意, pop() 函数的返回值是 double 型 */
	double item2 = pop();

	push(item1);
	push(item2);
}

/* clear_stack: clear the stack */
void clear_stack(void)
{
	sp = 0;
}
