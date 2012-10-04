#include<stdio.h>
#define MAXLINE		1000	/* maximum input line length */

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

/* Revise the main routine of the longest-line program so it will correctly
 * print the length of arbitrary long input lines, and as much as possible
 * of the text. 这里要求修改之前的main主程序,使它能正确计算输入的字符个数.
 * 虽然它定下了1000个字符的限制,但是通过修改main()程序,超过一千字的,只计算
 * 字符个数而不打印超出的部分.
 */
int main()
{
	int c;
	int len;				/* current line length */
	int max;				/* maximum length seen so far */
	char line[MAXLINE];		/* current input line */
	char longest[MAXLINE];	/* longest line saved here */

	max = 0;
	while ((len = getLine(line, MAXLINE)) > 0) {
		/* 在 getLine() 函数中,它为每个不超过1000字符的字符数组都添加了一个
		 * 回车,如果line字符数组的倒数第二个字符不是回车(倒数第一个字符是
		 * '\0'),则说明刚才输入的字符串超过了1000个字符,下面就需要重新计算
		 * 依然存留在内存缓冲区中的字符数目,来统计该字符串的真正长度.
		 */
		if (line[len - 1] != '\n') {
			while ((c = getchar()) != EOF && c != '\n')
				++len;
			if (c == '\n')
				++len;
		}
		if (len > max) {
			max = len;
			copy (longest, line);
		}
	}
	if (max > 0)		/* there was a line */
		printf("Longest is %d characters: %s", max, longest);
	return 0;
}

/* getline: read a line into s, return length */
int getLine(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';		/* C风格字符串要求以 '\0' 结尾 */
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;
	
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
