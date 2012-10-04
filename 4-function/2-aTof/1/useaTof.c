#include <stdio.h>
#define MAXLINE 1000

/* The reason a mismatch can happen is that if there is no function
 * prototype, a function is implicitly declared by its first appearance in
 * an expression, such as sum += aTof(line). If a name that has not been
 * previously declared occurs in an expression and it followed by a left
 * parentheses, it is declared by context to be a function name, the
 * function is assumed to return an int, and nothing is assumed about its
 * arguments. //// If the function takes arguments, declare them; if it
 * takes no arguments, use void (This is a good idea).
 */

/* rudimentary calculator, barely adequate for check-book balancing */
int main()
{
	/* 一般函数声明都是放在main()函数上面、头文件下面,如同声明外部变量一样,
	 * 使得该函数在源文件中全局可见; 但是,函数声明也可以声明为局部,如同局部
	 * 变量一样,如下所示. 由此可知,声明函数的方法和声明变量的方法是一致的.
	 * 甚至可以引申出,使用函数的方法和使用变量的方法也是一致的.变量名是标识
	 * 符,函数名也是标识符;变量拥有值,函数也可以拥有值;变量有类型,函数也有
	 * 类型... 认真领悟下面函数声明的用法,一定能够有新的启发.
	 */
	double sum, aTof(const char s[]);
	char line[MAXLINE];
	int getLine(char s[], int lim);

	sum = 0;
	while (getLine(line, MAXLINE) > 0)
		printf("\t%g\n", sum += aTof(line));
	return 0;
}

/* 由于 aTof()函数仅在 main()函数中作局部声明,所以 aTof()函数对 foo()函数
 * 不是显式可见的,编译该函数时会报错. 注意领悟这其中的差别,会有所启发.
 */
/*
void foo(void)
{
	char a[] = "404.8";
	aTof(a);
}
*/
