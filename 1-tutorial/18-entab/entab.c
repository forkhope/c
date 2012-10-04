#include <stdio.h>

#define MAXLINE		1000	/* getLine() 函数所获取字符串的最大长度 */
#define TABSIZE		4		/* 列表符占 4 个空格 */

int getLine(char line[], int maxline);

/* Write a program entab that replaces strings of blanks by the minimum
 * number of tabs and blanks to achieve the same spacing.题目的意思是如果有
 * 四个连续的空格,就将这四个连续的空格替换为一个列表符,使得最后的字符串的空
 * 格数和列表符数最少.
 */
int main()
{
	char line[MAXLINE];	
	int len, i, j, bksize;

	while ((len = getLine(line, MAXLINE)) > 0) {
		bksize = 0;	 //每获取一个新行,就将bksize变量清零,避免上一行的干扰
		for (i = 0, j = 0; j < len; ++j) {
			if (line[j] == ' ')
				++bksize;	//统计连续的空格数
			else
				bksize = 0;	//连续空格数清零
			line[i++] = line[j];
			if (bksize == TABSIZE) {
				i -= 4;	//如果连续空格数已经等于4,就将这四个空格换成列表符
				line[i++] = '\t';
				bksize = 0;	//替换之后,将连续空格数清零
			}
		}
		line[i] = '\0';	//使用 '\0' 来截断line字符数组后面不用的字符
		printf("%s", line);
	}
	return 0;
}

/* getLine: read a line into s, return length */
int getLine(char s[], int limit)
{
	int i, c;
	for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
