#include <stdio.h>

void printNum();
void showString(const char s1[], char s2[]);

/* If the variable in question is not automatic, the initialization is done
 * once only, conceptionally before the program starts executing, and the
 * initializer must be a constant expression. External and static variables
 * are initialized to zero by default. 外部变量在main()函数执行之前被初始化
 */
int number = 10;
int external_default;	// 未初始化的外部变量会被默认初始化为 0

/* All variables must be declared before use, although certain declarations
 * can be made implicitly by content. A declaration specifies a type, and
 * contains a list of one or more variables of that type.
 */
int main()
{
	/* 声明未初始化局部变量, Automatic variables for which is no explicit
     * initializer have undefined(i.e., garbage) values.
	 */
	int i, result;	// 此时, i 和 result 的值未知,依赖于具体的编译器和系统
	/* The qualifier const can be applied to the declaratio of any variable
	 * to specify that its value will not be changed.For an array,the const
	 * qualifier says that the elements will not be altered.
	 */
	const int lower = 1, upper = 99, step = 2;
	const char msg[] = "1 + 3 + 5 + ...... + 99 = ";
	/* 这里, msg的数组元素不可改变,如果试图改变它的元素的值,如msg[4] = 's';
	 * 则会报错:error: assignment of read-only * location ‘msg[4]’. 
	 */

	/* 初始化上面未初始化的局部变量 */
	result = 0;
	for (i = lower; i <= upper; i += step)
		result += i;
	printf("%s%d\n", msg, result);

	static int static_default; // 未初始化的静态变量会被默认初始化为 0
	printf("external_default = %d\nstatic_default = %d\n",
			external_default, static_default);

	printNum();
	printNum();

	char s1[] = "Initialized : ";
	char s2[] = "error";
	showString(s1, s2);
	printf("Altered : %s\n", s2);

	return 0;
}

/* 从程序执行的过程来看,外部变量在main()函数执行就被初始化,之后程序不会再执
 * 行外部变量的语句,所以外部变量只会被初始化一次;而局部变量的初始化语句是在
 * 函数里面,函数每次执行时,都会执行局部变量的初始化语句,所以一个显式初始化
 * 的局部变量随着函数的多次执行而多次被初始化.下面的函数分别修改了一个局部
 * 变量和一个外部变量的值,但是当函数再次执行时,局部变量的值又被初始化语句重
 * 置为原先的值,所以不管调用多少次,函数对局部变量的修改都会失效;而外部变量
 * 没有再次被初始化,它会保存函数对它的修改,函数每调用一次,它的值就改变一次.
 */
void printNum()
{
	/* A variable may also be initialized in its declaration. An explicitly
	 * initialized automatic variable is initialized each time the function
	 * or block it is in is entered; the initializer may be any expression.
	 */
	int m = 10;

	printf("----------------------------------\n");
	printf("initialized: m = %d\n", m);
	m += 34;
	printf("altered: m = %d\n", m);

	printf("number = %d\n", number);
	number += 4;
	printf("----------------------------------\n");
}

/* 虽然showString()函数的参数列表是(const char s1[], char s2[]),但是传进来
 * 的s1数组并不一定要是const char类型,char类型的字符数组也可以.
 */
void showString(const char s1[], char s2[])
{
	printf("%s%s\n", s1, s2);
	s2[0] = 'E'; // 数组参数属于传地址调用,这里修改了原先数组元素的内容.
	/* The const declaration can also be used with array arguments, to
	 * indicate that the function does not change that array.由于数组名相当
	 * 于地址,所以数组作为参数时,函数可以通过传进来的数组名来修改数组的内容,
	 * 如果不想让函数修改数组的内容,可以用const来限定传进来的数组参数,此时就
	 * 不能修改了,如果用s1[3] = 'x'来修改的话,会报错: error: assignment of 
	 * read-only location '*(s1 + 3u)'.
	 */
}
