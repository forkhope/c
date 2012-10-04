#include <stdio.h>

extern void strCat(char *s, const char *t);

/* 测试 strCat() 函数 */
int main(void)
{
	/* 下面三条语句在编译时不会报任何错误,但在执行时,会抛出段错误异常.
	 * 因为 p 指向的是字符常量区,如果改变这里面的内容,其后果没有定义.
	 * char *p = "tian"; char *q = " xia"; strCat(p, q);
	 */

	char p[20] = "tian";
	char *q = " xia";

	strCat(p, q);
	printf("%s\n", p);
	return 0;
}
