#include<stdio.h>

/* count lines in input. The standary library ensures that an input text 
 * stream appears as a sequence of lines, each terminated by a newline. 
 * Hence, counting lines is just counting newlines.
 */
int main()
{
	int c, nl;

	nl = 0;
	while ((c = getchar()) != EOF) 
		if (c == '\n')	// 统计回车数来得到行数,行与行之间通过回车来界定
			++nl;
	printf("输入的行数(回车个数)为: %d\n", nl);

	// A character constant is just another way to write a small integer.
	// 所以 表达式('\n' == 10) 的值为真,如下所示:
	if ('\n' == 10)		// '\n' == 10 为真,下面的表达式得到执行
		printf("%d%c", '\n', '\n');
	return 0;
}
