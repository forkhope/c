#include<stdio.h>

int CalcNumberOfSpace(int len, int tabsize);

/* Write a program detab that replaces tabs in the input with the proper
 * number of blanks to space to the next tab stop. Assume a fixed set of 
 * tab stops, say every n columns. Should n be a variable or a symbolic 
 * parameter? 这个题目是要求将输入中的tab替换为一定数量的空格,使得下文正好
 * 从下一个tab起始列开始,假设每个tab固定是n个字符,则每个单词的首字母都正好
 * 在第0列,第n列,第2*n列......即单词的首字母按列对齐.题目中还问这个tab固定
 * 的空格数量是否应该以变量的形式出现,回答是应该,这样tab固定的空格数量就可
 * 以在运行时指定,例如通过命令行参数来指定tab固定的空格数量,这样更灵活适用
 */
int main()
{
	int c, i, j,  len, tabsize;

	tabsize = 5;
	len = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			/* CalcNumberOfSpace() 函数计算填充的空格数目,并返回这个值 */
			j = CalcNumberOfSpace(len, tabsize);
			for (i = 0; i < j; ++i)
				putchar(' ');
			len = len + j;
		}
		else if (c == '\n') {
			putchar('\n');
			len = 0;
		}
		else {
			putchar(c);
			++len;
		}
	}
	return 0;
}

int CalcNumberOfSpace(int len, int tabsize)
{
	// 先求模得到多出来的数目,再减去这个数目得到不足的数目,并返回这个数目
	return (tabsize - len % tabsize);
}
