#include <stdio.h>

#define MAXVAL	100		/* 栈空间大小 */
int sp = 0;				/* 指向栈中下一个可用的位置 */
double val[MAXVAL];		/* 栈空间,存放双精度浮点操作数 */

void push(const double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full,can't push %g\n", f);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}
