#include <stdio.h>

#ifdef UNALIGN
#pragma pack(1)		// 该预处理指令指定按 1 字节对齐
#endif

/* 探讨 结构体 的字节对齐问题,并介绍 gcc 调试宏的使用.
 * gcc 的选项参数 -Dmacro 可以在编译时定义一个宏,当然也可以写为 -D macro,
 * 空格有没有都没关系;比如gcc -DUNALIGN 就能在编译时定义个宏UNALIGN,则上面
 * 的#ifdef判断为真,会执行预处理执行 #pragma pack(1),程序中的结构体都以 1
 * 字节对齐, sizeof 计算出的结果和编译器默认设置下得到的值不同;同时,还可以
 * 使用选项 -Umacor 来取消宏macro的定义,同样可以写为 -U macro.
 */
int main(void)
{
	/* 结构体的字节长度(用sizeof操作符计算出的长度)等于所有成员字节长度之和
	 * 然而,使用sizeof操作符计算出来的结果并不一定等于所有成员的字节长度之和
	 * 这取决于编译器的设定.编译器一般会对结构体的存储空间进行字节对齐.默认
	 * 情况下,以结构体中字节长度最长的成员为基准,进行对齐. 所谓以n对齐,指
	 * 的是实际的存储的字节数应该是 n  的倍数.
	 */

	/* 以下注释中说的结构体字节长度都是在编译器的默认设置下获取的.当使用 
	 * #pragma pack(1) 将对齐字节设为 1时,所得到的长度不是下面所说的结果
	 */

	/* 结构体a 中字节长度最长的成员是 int i,四个字节,所以其他成员的存储空间
	 * 会向4字节对齐,即 char a 也要占4个字节;因此,结构体a 的字节长度是8.
	 */
	struct a {
		char c;
		int i;
	};

	/* 同上,结构体b 也要以4字节对齐,由于 char c 和 char ch 加起来占 2 个字节
	 * 向4字节对齐后,这两个占4个字节;因此,结构体b 的字节长度是8.
	 */
	struct b {
		char c;
		char ch;
		int i;
	};

	/* 结构体c 中,字节长度最长的成员是 short o,占两个字节,所以该结构体的
	 * 存储字节数向 2 字节对齐.则 char c 占2个字节;因此,结构体c 占4个字节
	 */
	struct c {
		char c;
		short o;
	};

	/* char c 和 char ch 合起来占两个字节,刚好是以2字节对齐,所以这里没有
	 * 占用多余的空间,结构体d 的字节长度是 4.
	 */
	struct d {
		char c;
		char ch;
		short o;
	};
	
	/* 注意这里不能写为 sizeof a,否则会报错,因为sizeof 后面跟数据类型时,
	 * 数据类型要用括号括起来,且如果希望计算结构体a 的字节长度,要加struct
	 */
	printf("%d\n", sizeof(struct a));
	printf("%d\n", sizeof(struct b));
	printf("%d\n", sizeof(struct c));
	printf("%d\n", sizeof(struct d));
	return 0;
}
