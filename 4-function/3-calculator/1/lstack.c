/* 定义一个简单的栈,并实现对栈的基本操作 : 压栈、出栈 */
#include <stdio.h>
#define MAXVAL	100		/* maximum depth of val stack */

int sp = 0;		/* next free stack position. sp 指向栈顶元素的上一个位置 */
double val[MAXVAL];		/* value stack. 栈空间 */

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)	/* 当函数不接收参数时,使用 void 来显式限定 */
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}
