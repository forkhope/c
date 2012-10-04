#include <stdio.h>

/* 主要探讨一下 字符串常量 和 字符数组 的区别 */
int main(void)
{
	/* There is an important difference between these definitions:
	 * char amessage[] = "now is the time";  // an array
	 * char *pmessage = "now is the time";   // a pointer
	 * amessage is an array, just big enough to hold the sequence of
	 * characters and '\0' that initializes it. Individual characters within
	 * the array may be changed but amessage will always refer to the same
	 * storage. On the other hand, pmessage is a pointer, initialized to
	 * point to a string contant; the pointer may subsequently be modified
	 * to point elsewhere, but the result is undefined if you try to modify
	 * the string contents,这种情况在linux下,编译时不报错,但运行会报段错误.
	 */
	char *p = "tian";	/* p 存在栈中, "tian"存在字符常量区 */
	char *q = "tian";	/* t 存在栈中, "tian"存在字符常量区
						 * 编译器可能会让t和p指向常量区中的同一个"tian".
						 */
	char a[] = "tian";	/* "tian"中的所有字符被分开存放在栈中 */
	//int i = 4;
	char b[] = "tian";	/* "tian"中的所有字符被分开存放在栈中 */

	printf("输出 p、q、a、和 b 的地址如下:\n");
	printf("p = %d\n", (int)p);
	printf("q = %d\n", (int)q);
	printf("a = %d\n", (int)a);
	printf("b = %d\n", (int)b);

	/* 从多次执行的输出结果来看, p 和 q 总是相等, 而 a 和 b 之间总是相差 5
	 * 这个值刚好是字符串"tian"包含的所有字符的数目(隐含有一个'\0').即 a 和
	 * b 在栈中是顺序存放的.奇怪的是,在 a 和 b 的定义语句之间加上语句int i;
	 * a 和 b 之间依然是相差 5,而不是相差 9,这个问题需要进一步探讨.
	 */

	return 0;
}
