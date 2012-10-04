#include <stdio.h>

extern void strCpy(char *s, char *t);

/* 测试 strCpy() 函数 */
int main(void)
{
	char *p = "tianxia";
	/* 注意,下面两句代码在编译时会报警告,运行时抛出段错误异常,因为指针q没有
	 * 被初始化,即q指向的地址是未知的,向未知的地址写入数据,引发了段错误异常
	 * char *q; strCpy(q, p);	// 这两句在编译时报警告,运行时报段错误
	 */
	char a[10];

	strCpy(a, p);
	printf("%s\n", a);
	return 0;
}
