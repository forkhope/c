#include <stdio.h>

/* A union is a variable that may hold (at different times) objects of
 * different types and sizes, with the compiler keeping track of size and
 * alignment requirements. In effect, a union is a structure in which all
 * members have offset zero from the base, the structure is big enough to
 * hold the "widest" member, and the alignment is appropriate for all of
 * the types in the union. The same operations are permitted on unions as
 * on structures: assignment to or copying as a unit, taking the address,
 * and accessing a member. A union may only be initialized with a value of 
 * the type of its first members;
 * 在 union 中,所有成员不能同时占用它的内存空间,它们不能同时存在.union 变量
 * 的内存长度等于其最长的成员的长度. union 的用法和 struct 一致.
 */
union u_tab {
	unsigned int ival;
	char *sval;
};

/* 举例描述 union 的用法 */
int main(void)
{
	union u_tab  u;	/* 定义一个 u_tab 类型的变量u */
	char *p = "tian";
	union u_tab a[] = {
		/* 根据上面的描述的 union 初始化规则,下面如果使用 p 来为 a[1] 
		 * 赋初值,编译时会告警,告警信息如下:
		 * warning:initialization makes integer from pointer without a cast
		 * 这个告警信息表示,试图用没有经过转换的指针值来为整数赋值.
		 * 另外,虽然 union 类型有多个成员,但是一个union变量每次只能保存一个
		 * 成员的值,在初始化时,不能初始化union变量多个成员的值,例如下面如果
		 * 用 {1, 3} 来为 a[0] 赋初值,编译器会告警,但不会报错,告警信息为:
		 * warning: excess elements in union initializer
		 * warning: (near initialization for ‘a[0]’)
		 */
		{1}, {(int)p}	// 为了避免告警信息,使用 (int)p 来作强制转换
	};

	printf("a[0] = %u, a[1] = %s\n", a[0].ival, a[1].sval);
	printf("size of u is %d\n", sizeof u);

	/* 结构体变量可以相互之间整体赋值,联合当然也可以,虽然这没有太大的意义,
	 * 因为联合本来就只能保存一个成员的值,不存在多个成员整体赋值的说法.
	 */
	u = a[0];	/* 用 a[0] 保存的成员值 来为 u 赋值. */
	printf("u.ival = %d, u.sval = %p\n", u.ival, u.sval);

	/* 这里一定要注意,联合变量相互之间可以直接赋值,其他类型变量和联合变量
	 * 之间不能直接赋值,只能使用类型相符的变量来为联合变量的成员赋值,这里
	 * 说的类型相符包括可以强制转换的类型.例如, float 和 int 可以强制转换
	 * 而 int 和 拥有多个成员的结构体类型就不能强制转换.
	 */

	/* 此时, u 是 u_tab 联合类型的变量,它即不是整型变量,也不是字符指针变量,
	 * 使用 整型变量 或者 字符指针变量 直接为 u 赋值,都会报错.
	 */
	// u = 1;   // 会报错, u 不是整型变量
	// u = p;	// 会报错, u 也不是字符指针变量
	// 如同结构体的用法一样,可以用整型变量或者字符指针变量来为u的成员赋值
	u.ival = 2;		/* 先为整型成员 ival 赋值为 2 */
	printf("u.ival = %u\n", u.ival);
	/* 注意, union 类型变量只能存放一个成员的值,再次赋值,将会覆盖之前的成员
	 * 值,即使是分别为不同的成员赋值.这是因为根据上面的描述, union 所有成员
	 * 的内存起始地址是一样的,每次赋值,写入的是相同的地址,从而覆盖之前的值.
	 */
	u.sval = p;		/* 再为字符指针成员 sval 赋值为 p */
	/* 此时,再次打印 u.ival 的值,结果不再是 2,而是 p 这个指针所指向的内存
	 * 地址的值,下面打印出来的两个值应该是相等的.
	 */
	printf("u.ival = %x, u.sval = %p\n", u.ival, u.sval);

	/* 从上面可以看出, 抛开数据结构类型上的区别, u.ival 和 u.sval 在数值上
	 * 是相等的,而在 printf() 函数中,是通过格式字符来指定要格式化的数据类型
	 * 同样的数值,使用 %d 格式化,表示要把该数值看作整型变量,使用 %s 格式化,
	 * 表示要把该数值看作字符指针变量,则此时,可以使用 u.sval 来打印整数的值
	 * 的值,也可以使用 u.ival 来打印一个字符串,需要类型转换,避免编译器告警.
	 *
	 * 这里,仅仅是为了表明可以这样使用,实际用的时候,还是要按数据类型来使用.
	 */
	/* 上面是为 u.sval 赋值为 p, 但是可以通过 u.ival 来引用 p 的值 */
	printf("%s\n", (char *)u.ival);
	/* 下面为 u.ival 赋值为 3, 同样可以通过 u.sval 来打印出这个 3 */
	u.ival = 3;
	printf("%u\n", (unsigned int)u.sval);

	return 0;
}
