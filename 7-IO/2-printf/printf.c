#include <stdio.h>

int main(void)
{
	int i = 14;
	/* %d, %i : 打印 int 型变量,十进制 */
	printf("十进制 i = %d, i = %i\n", i, i);
	/* %o : 打印 int 型变量,无符号八进制,没有前置的 0 */
	printf("八进制 i = %o\n", i);
	/* %x, %X : 打印 int 型变量,无符号十六进制,没有前置的 0x 或者 0X */
	printf("十六进制 i = %x, i = %X\n", i, i);
	
	unsigned int u = 8;
	/* %u : 打印 unsigned int 型变量,无符号十进制 */
	printf("无符号十进制 u = %u\n", u);

	char c = '9';
	int a = 't';
	/* %c : 打印单个字符. 对应的变量类型是 int 型,char 会被扩展为 int */
	printf("打印单个字符 c = %c, a = %c\n", c, a);

	char *s = "tian xia";
	/* %s : 打印一个字符串,对应的变量类型是 char * 类型 */
	printf("%s\n", s);
	/* 百分号 和 格式码 之间可以有域宽说明符和精度说明符,两者之间用'.'号隔
	 * 开,当字符串或者数字少于指定域宽时,printf()用空格填至指定域宽;字符串
	 * 或者数字多于指定域宽时,不会发生截断,内容会全部显示;
	 * 域宽表明的是最小宽度,精度表明的是最大宽度,当字符串或者数字小于精度时
	 * 会发生截断,当字符串或者数字多于精度时,没有影响.
	 */
	printf("%s:\n", "hello, world");
	printf("%10s:\n", "hello, world");	/* 域宽小于字符串长度,没有影响 */	
	printf("%.10s:\n", "hello, world");	/* 精度小于字符串长度,发生截断 */
	printf("%-10s:\n", "hello, world");	/* %- 表示字符串向左对齐 */
	printf("%.15s:\n", "hello, world");	/* 精度大于字符串长度,没有影响 */
	printf("%-15s:\n", "hello, world");	/* 域宽大于字符串长度,发生填充 */
	printf("%15.10s:\n", "hello, world");
	printf("%-15.10s:\n", "hello, world");

	/* 左对齐 和 右对齐; printf()函数中,默认是右对齐,当打印的字符个数小于
	 * 域宽时,字符会向右对齐;可以通过 %- 来改为左对齐,如下所示:
	 */
	printf("%6s %6s\n", "tian", "xia");
	printf("%-6s %-6s\n", "tian", "xia"); /* 注意,不能写为%6-s,否则报错 */

	/* A width or precision may be specified as *, in which case the value
	 * is computed by converting the next argument (which must be an int).
	 * 即,可以动态的指定域宽和精度,我感觉这个很有用,可以用于防止字符串溢出
	 * 的情况,指定一个精度后,即使字符串溢出,后果也稍微可控.
	 */
	printf("%*.*s\n", 10, 7, "you qing ren");

	float f = 9089.590;
	double d = 388502.8080;
	/* %f : 打印 double 类型的变量, float 会被扩展为 double, 默认打印出的
	 * 小数点位数是 6 位,这个数字可以被改变.
	 */
	printf("默认的小数点位数: f = %f, d = %f\n", f, d);
	printf("设置小数点位数为 8: f = %.8f, d = %.8f\n", f, d);
	/* %e, %E : 使用自然记数法来打印 double 类型的变量 */
	printf("自然记数法: f = %e, d = %E\n", f, d);
	/* %g, %G : 程序会根据所给的变量选择采用自然记数法或是一般的记法来打印
	 * double 类型的变量.
	 */
	printf("f = %g, d = %G\n", f, d);

	void *p = s;
	/* %p : 对应的变量是 void * 类型, 打印出的值由程序实现所决定 */
	printf("%p\n", p);

	/* %% : 不进行转换,仅仅打印一个字符 '%' */
	printf("%%\n");

	return 0;
}
