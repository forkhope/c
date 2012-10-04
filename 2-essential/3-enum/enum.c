#include <stdio.h>

/* There is one other kind of constant, the enumeration constant. An 
 * enumeration is a list of constant integer values.使用枚举时,尽量使用
 * 枚举成员,而不是定义枚举变量,枚举成员的值是常量,而枚举变量的值不是常量.
 */
int main()
{
	/* 下面定义了一种枚举类型,枚举类型实际上就是一组整数常量、也只能是整数
	 * 常量的集合,并为每一个整数常量定义一个标识符,整数常量之间用逗号分开,
	 * The first name in an enum has value 0, the next 1, and so on, unless
	 * explicit values are specified. If not all values are specified,
	 * unspecified values continue the progression from the last specified
	 * value. Values need not be distinct in the same enumeration.
	 */
	enum BOOL { FALSE, TRUE }; // 没有显示赋值,则默认地 FALSE = 0,TRUE = 1
	printf("FALSE = %d, TRUE = %d\n", FALSE, TRUE);
	enum months { JAN = 1, FEB, MAR, APR, MAY, JUN,
			JUL, AUG, SEP, OCT, NOV, DEC }; // 声明了一个枚举类型变量months
	/* 注意,在声明和定义枚举变量时,枚举类型的变量前面也要加enum关键字,这和
	 * struct关键字一样,除非使用typedef来建立新的数据类型名,否则enum不能少.
	 */
	enum months curMonth = JUL;	// 如果去掉 enum 关键字,会报错
	enum months preMonth = JUN;	// 使用枚举成员为枚举变量赋值
	enum months nexMonth = AUG; 
	printf("curMonth = %d, preMonth = %d, nexMonth = %d\n", 
			curMonth, preMonth, nexMonth);
	/* 枚举成员就是一个表示了整数常量的标识符,当作整数常量来使用就好.即使
	 * 没有定义枚举变量,也可以直接单独使用枚举成员,但是不能为枚举成员赋值,
	 * 因为枚举成员都是整数常量,它们的值不可改变,而枚举变量的值可以改变,且
	 * 改变后的值可以不在枚举成员列表中,且可以是float型,但不能是字符串常量
	 */
	printf("OCT = JUL + 3 = %d\n", JUL + 3);
	/* 也可以使用整数常量来为枚举变量赋值,这个值甚至不在枚举成员列表中 */
	enum months oneMonth = 49;
	/* 使用浮点数来改变oneMonth变量的值是可以的.但要注意,此时oneMonth等于82
	 * 而不是等于82.9,后面的小数部分被截断了,用oneMonth为float型变量赋值可以
	 * 清晰地看到这一点.且用printf("%f\n",oneMonth);来打印oneMonth的值时会
	 * 报警告:warning: format '%f' expects type 'double' but argument 2 has 
	 * type 'unsigned int'.
	 */
	oneMonth = 82.9;
	float i = oneMonth;
	printf("oneMonth = %d, i = %f\n", oneMonth, i);

	/* 同一枚举的不同成员可以拥有相同的值 */
	enum scores { C = 92, JAVA, PYTHON = 95, PERL = 95, PHP, ASP };
	printf("Your scores are JAVA = %d, JSP = %d\n", JAVA, ASP);

	/* 用字符串来为oneMonth赋值,如oneMonth="aug";会报错:error:incompatible 
	 * types when assigning to type ‘enum months’ from type ‘char *’
	 */

	/* 枚举成员的取值只能是整数常量,如果取值不是整数常量,例如文件中有这样一
	 * 句: enum wrongEnum { AA = 1.3, BB = 3.1 }; 则编译时会报如下的错误:
	 * enum.c:error:enumerator value for ‘AA’ is not an integer constant
	 * enum.c:error:enumerator value for ‘BB’ is not an integer constant
	 * make: *** [enum] 错误 1
	 */
	
	return 0;
}
