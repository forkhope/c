#include<stdio.h>

void func1();
void func2(void);

/* 函数定义void func1() 是老式的C语言写法,当这样写的时候,表明该函数的参数
 * 列表为空,并关闭对参数列表的检查,由于关闭对参数列表的检查,在调用该函数时,
 * 可以传递任意类型的参数,而不会引起语法错误. 函数定义void func2(void) 是
 * ANSI C中的标准写法,显式表明该函数的参数列表为空,不能为该函数传递任何参数
 * 书中建议: If the function takes arguments, declare them; if it takes no
 * arguments, use void.
 */
int main()
{
	/* 由于 func1 函数的定义是 void func1(),所以在调用该函数时,可以传递任意
	 * 类型的参数,如下所示,在编译时,不会报错,不会引起语法错误,可以正确运行
	 */
	func1(2, "tian", 'a');

	/* 由于 func2 函数的定义是 void func2(void),所以在调用该函数时,不能传递
	 * 任何参数,像写成 func2(3) 编译器就会报错,编译器给出的错误信息如下:
	 * voidargu.c: In function ‘main’:
	 * voidargu.c:20: error: too many arguments to function ‘func2’
	 */
	func2();
	return 0;
}

void func1()
{
	printf("This is in the func1\n");
}

void func2(void)
{
	printf("This is in the func2\n");
}
