#include <stdio.h>
#include "lstring.h"

/* 测试 lstring.c 中实现的三个函数: strnCpy(), strnCmp(), strnCat() */
int main(void)
{
	char p[20] = "xirn";
	char q[4] = "xia";
	char t[9];

	printf("strnCmp(p, q, 2) = %d\n", strnCmp(p, q, 2));
	printf("strnCmp(p, q, 3) = %d\n", strnCmp(p, q, 3));
	printf("strnCmp(p, q, 4) = %d\n", strnCmp(p, q, 4));

	strnCat(p, q, 2);
	printf("执行strnCat(p, q, 2)后,p = %s\n", p);
	strnCat(p, q, 5);
	printf("执行strnCat(p, q, 5)后,p = %s\n", p);

	strnCpy(t, p, 5);
	printf("执行strnCpy(t, p, 5)后,t = %s\n", t);
	/* 下面使用strnCpy()函数的方式可能会带来一些问题,其结果依strncpy()函数
	 * 的不同实现而不同.因为数组t的大小是9,而此时数组p[]=="xirnxixia",则
	 * 执行strnCpy(t,p,9)后,字符数组t中没有多余的位置来存放'\0'字符,这在C
	 * 语言中,是大忌!而程序中实现的strnCpy()函数能保证复制后的字符串一定是
	 * 以'\0'结尾(这里,t[8]后面的字符就等于'\0'),所以使用 t 时,结果有可能
	 * 是正确的,例如下面的printf()打印出的t 就是正确的.但是t[8]后面的字符
	 * 并不在数组t 的控制之下,这个字符有可能被分配给其他的变量,并写入其他的
	 * 值;这时,再使用数组t 的话,就很有可能会发生数组越界的情况.
	 */
	strnCpy(t, p, 9);
	printf("执行strnCpy(t, p, 9)后,t = %s\n", t);
	/* 为了防止上面所说的情况出现,使用strnCpy()函数或者是strncpy()函数时,
	 * 可以采用下面的写法来避免,虽然下面的写法会稍显怪异及复杂,但这是值得的
	 */
	strnCpy(t, p, sizeof(t) - 1); /* 若数组t有9个元素,则最多只复制8个 */
	t[sizeof(t)-1] = '\0'; /* 将t 的最后元素置为'\0',避免上面所说的情况 */
	printf("执行strnCpy(t,p,sizeof(t)-1)后,t = %s\n", t);
	return 0;
}
