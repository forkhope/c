#include <stdio.h>

/* int scanf(char *format, ...);
 * scanf() reads characters from the standard input, interprets them 
 * according to the specification in format, and stores the results through
 * the remaining argumetns. It returns as its value the number of
 * successfully matched and assigned input items, This can be used to decide
 * how many items were found. On the end of file, EOF is returned; not that
 * this is different from 0, which means that the next input character does
 * not match the first specification in the format string. The next call to
 * scanf() resumes searching immediately after the last character already
 * converted. There is also a function sscanf that reads from a string
 * instead of the standard input:
 * int sscanf(char *string, char *format, arg1, arg2, ...);
 */
int main(void)
{
	int date, month, year;
	int i;
	char c, buf[5];
	double sum, v;

	/* 下面的scanf语句,如果输入的是 8  8 2011,则输出的是:
	 * 8/134513824/-1217056780
	 * 可以看到,只有 date 被赋值, month 和 year 都没有被赋值; 这是因为当
	 * scanf()里面的格式化字符串为 %d/%d%d 时,只有输入 '/', scanf() 才会为
	 * 下一个变量赋值,当输入的是 8/8/2011 时,输出就会是 8/8/2011.
	 */
	i = scanf("%d/%d/%d", &date, &month, &year);
	printf("%d/%d/%d\n", date, month, year);

	/* scanf()函数返回一个int型的值,表明遇到了多少个正确类型的输入;当输入是
	 * EOF字符时,该函数返回EOF的整型值;当输入全都不匹配时,返回的是0.
	 */
	if (i == EOF) /* 当上面的输入只输入EOF时,可以看到下面的字符串被输出 */
		printf("The input is EOF\n");	/* 表明scanf()函数返回了 EOF */
	if (i == 0)	/* 当输入全都不匹配整型值时,可以看到下面的字符串被输出 */
		printf("There were not matched\n");	/* 表明scanf()函数了 0 */

	/* 程序中有两个scanf()语句,可能是希望第一次输入完之后,按下回车,再进行
	 * 第二次输入;但实际情况并不是这样,在该程序中,按下一次回车后,就会结束
	 * 所有的输入; 如果输入的 8/8/2011 回车,则输出是:
	 * 8/8/2011	// 输入完 8/8/2001 后,按下回车,程序会结束所有的输入
	 *			// 这里有一个回车,是上面printf()语句里面的回车
	 *			// 这里有一个回车,是刚此输入的回车,空白字符不被忽略,c='\n'
	 *			// 这里有一个回车,是下面printf()语句里面的回车
	 * 如果希望按下回车,仅仅结束第一次输入的话,上面的scanf()语句的格式化
	 * 字符串的末尾应该加上'\n'字符,形如 %d/%d/%d\n. 
	 * 另外,如果上一次scanf()语句执行出错,有一部分字符还留在缓冲区中没有读,
	 * 则下面调用scanf()语句时,会读取缓冲区中存留的字符,而不是读取最新输入
	 * 的字符.例如,在该程序中,当输入 8/8/2011/ a 时,可能希望是将下面的c赋值
	 * 为 'a',但其实, c 会被赋值为 '/'.
	 */
	scanf("%c", &c);
	printf("%c\n", c);

	/* 程序可以使用scanf()函数的返回值来判断是否所有变量都已经被赋值,这样
	 * 可以防止因为无效输入,导致变量没有被赋值、甚至是没有被初始化的情况.
	 */
	if (scanf("%d/%d/%d", &date, &month, &year) == 3) 
		printf("valid: %d/%d/%d\n", date, month, year);
	else
		printf("error: invalid input, please retry\n");

	/* printf()函数的百分号% 和 格式码之间可以有域宽说明符和精度说明符,两者
	 * 用'.'隔开;但是, scanf 只有精度说明符,没有域宽说明符,也不能加上'.',
	 * scanf("%4s", buf); 表示最多只读入4个字符,多余字符不会被存入buf中.
	 */
	scanf("%4s", buf);
	/* 字符数组char buf[5]里面的元素被默认初始化为'\0',但是为了明确起见,
	 * 下面一句还是要有,表示程序考虑到了字符串终止字符是否存在的问题.
	 */
	buf[4] = '\0';	
	printf("读入的字符串为: %s\n", buf);

	/* 最后,这是一个简单加法计算器的实现. 注意,下面的格式化字符串是 %lf,是
     * 字母l 和 字符f, 不是 数字1 和 字符f, 否则会报错,因为 %f 只对应float
	 * 类型,要对应double类型,要使用 %lf.
	 */
	sum = 0;
	while (scanf("%lf", &v) == 1)
		printf("\t%.2f\n", sum += v);

	return 0;
}
