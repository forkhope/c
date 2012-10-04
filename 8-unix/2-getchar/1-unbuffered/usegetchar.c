#include <stdio.h>

extern int getChar(void);

int main(void)
{
	int c;

	/* 该程序中,输入多个字符,会有不一样的结果,实际执行时,可分别输入:
	 * a回车、aaaaa回车、als回车
	 * 对比输出结果,会有一些启发.
	 * 使用while循环可以避免上述问题出现,如下:
	 * while ((c = getChar()) != EOF)
	 * 		putchar(c);
	 */
	c = getChar();
	if (c != EOF)
		printf("%c\n", c);

	return 0;
}
