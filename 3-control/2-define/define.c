#include <stdio.h>

/* 当一个宏被替换为多条语句时,用大括号把这些语句都放到一个语句块是一个好的
 * 选择.但是这样做有时会有一些问题,例如下面的if-else语句中,如果在FOO(2)宏
 * 后面加上分号,则宏展开之后,会变为如下的形式:
 * if (2 > 4) { 
 *     printf("The argument is %d\n", 2); 
	   printf("使用 FOO() 宏时,一定不要在宏的后面加分号,否则报错.\n"); \
 * };
 * else { 
 *     printf("The argument is %d\n", 4); 
	   printf("使用 FOO() 宏时,一定不要在宏的后面加分号,否则报错.\n"); \
 * };
 * if 语句的右括号后面被加上了一个分号,而在C 语言中,分号是表达式的终止符,
 * 所以原本期望的if-else语句被分成了if 语句和else 语句,但是else 语句是不能
 * 脱离if 语句而存在的,所以编译时就会报错: 'else' without a previous 'if'.
 * 可见,在使用如下的宏时,由于会习惯性的加上分号,在某些场合会带来预料之外的
 * 错误.其实,在C 语言中,用大括号括起来的语句块的右括号是不用加分号的,所以在
 * 使用这样的宏时,一定要记住不能加分号!
 * 定义多条语句的宏的另一种方法是使用do{...}while(0)循环来把多条语句括起来
 * 注意:定义宏时,while(0)后面没有分号,但 do{...}while(0)循环要求以分号结束
 * 所以使用这样的宏就要记得要后面加上分号!
 * 当然也可以在定义宏时,在while(0)后面加上分号,写为while(0);形式,则使用宏时
 * 不能在后面加分号,否则有时会带来无法预料的错误;这样做就没有什么意义.
 */
#define FOO(x) {\
	printf("The argument of macro FOO() is %d\n", x); \
	printf("使用 FOO() 宏时,一定不要在宏的后面加分号,否则报错.\n"); \
}

#define BAR(x) do { \
	printf("The argument of macro BAR() is %d\n", x); \
	printf("使用 BAR() 宏时,一定要在宏的后面加上分号,否则报错.\n"); \
} while(0)

int main()
{
	if (2 > 4)
		FOO(2)		/* 这里 FOO(2) 后面一定不能添加分号,否则会报错 */
	else
		FOO(4)		/* 这里 FOO(4) 后面可加分号,也可不加,一般是不加 */

	if (2 < 4)
		BAR(2);		/* 这里 BAR(2) 后面一定要加分号,否则会报错 */
	else
		BAR(4)		/* 同时,这里的 BAR(4) 后面也一定要加分号! */
	return 0;
}
