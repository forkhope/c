#include<stdio.h>

/* copy input to output */
int main()
{
	// getchar()函数返回所获取字符的ASCII码值,是一个整型值,
	// 所以这里要定义为int型,而不是char型
	int c;	

	printf ("注意:在输入的时候,可以输入多个字符,当按下Enter键后,所有输入的字符被送入内存缓冲区,之后 getchar()函数会从缓冲区取走第一个字符,再次调用该函数时,再从缓冲区取走下一个字符,直到缓冲区为空,这时再调用 getchar()函数,就需要键盘再次输入,并按下Enter键,将输入的字符送入内存缓冲区,该函数才能获取下一个字符.当输入一个字符时,getchar()并不能立即获取该字符,必须要按下Enter键才行\n");
	printf("输入文件结束符EOF结束程序:\n");
	/* c = getchar();		// 这样写,程序可以正常运行,但是代码略显繁复,
	while (c != EOF) {		// 不够简短,下面有一个更简短的写法,但是在采
		putchar(c);			// 用简短的写法时,要注意判断条件的正确写法,
		c = getchar();		// 注意括号的使用,注意多个运算符之间的优先级
	} */
	/* 更简短的写法.注意:c = getchar()表达式必须被括号括起来,否则执行结果和
	 * 预料不符.这涉及运算符的优先级,不等于号(!=) 的优先级大于 赋值号(=) 的
	 * 优先级,所以当写成 while (c = getchar() != EOF) 时,程序会把输入的第一
	 * 个字符和EOF进行比较,再将比较的结果赋给变量c,这和程序预期的想法不符.
	 */
	while ((c = getchar()) != EOF)
		putchar(c);

	printf("输入EOF宏对应的值: ");		// EOF宏 一般被定义为 -1
	printf("EOF = %d\n", EOF);
	return 0;
}