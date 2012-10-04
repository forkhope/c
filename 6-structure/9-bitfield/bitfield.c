#include <stdio.h>

/* bit-fields(位域) 是一种数据结构,它把一个字节中的二进位划分为几个不同的
 * 区域,并说明每个区域的位数.每一个域有一个域名,允许在程序中按域名进行操作.
 * 这样就可以把几个不同的对象用一个字节的二进制位域来表示. 位域的成员不能
 * 使用sizeof操作符,否则会报错.同时,不能对位域里面的成员取地址;
 */
int main(void)
{
	struct {
		unsigned int is_keyword : 1;
		unsigned int is_extern  : 1;
		unsigned int is_static  : 1;
	} flags;

	struct bitf{
		unsigned int a:2;
		/* The special width 0 may be used to force alignment at the next
		 * word boundary.位域可以没有域名,这时它只用于填充位置,无法被使用.
		 */
		unsigned int : 0;
		unsigned int b:4; /* 从下一个字节开始存放 */
	} bs;
	printf("%d\n", sizeof bs);

	/* 下面一句会报错,报错信息如下:
	 * bitfield.c:20: error: ‘sizeof’ applied to a bit-field
	 * bitfield.c:20: error: ‘sizeof’ applied to a bit-field
	 */
	//printf("%d %d\n", sizeof flags.is_keyword, sizeof flags.is_extern);

	flags.is_keyword = flags.is_extern = flags.is_static = 1;
	printf("%d %d %d\n", flags.is_keyword, flags.is_keyword, 
			flags.is_static);
	
	flags.is_keyword = flags.is_extern = flags.is_static = 0;
	printf("%d %d %d\n", flags.is_keyword, flags.is_keyword, 
			flags.is_static);

	/* 下面一句会报警(使用了gcc的全警报选项 -Wall),报警信息如下:
	 * warning: large integer implicitly truncated to unsigned type
	 */
	//flags.is_keyword = flags.is_extern = flags.is_static = 2;
	//printf("%d %d %d\n", flags.is_keyword, flags.is_keyword, 
	//		flags.is_static);
	return 0;
}
