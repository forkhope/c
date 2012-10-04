#include<stdio.h>
#define MINLENGTH 81		/* 可以输出的最短字符串长度 */

int getLine(char line[], int maxline);

/* print all input lines that are longer than 80 characters */
int main()
{
	int c;
	int len;				/* current line length */
	char line[MINLENGTH];	/* current input line */

	/* 如果用 #define MAXLINE 1000 来判定的话,程序就只能打印超过80但是小于
	 * 1000的输入行,而题意要求打印所有超过80个字符的输入行,所以改用下面的
	 * 方法来判定.如果输入行超过80个字符,它会将存留在缓冲区里的字符取出打印
	 */
	while ((len = getLine(line, MINLENGTH)) > 0) 
		if (line[len - 1] != '\n') {
			printf("%s", line);
			/* 下面的 c != '\n' 用来判定是否到达行尾,行与行通过回车界定 */
			while ((c = getchar()) != EOF && c != '\n')
				putchar(c);
			if (c == '\n')
				putchar(c);
		}
	return 0;
}

/* getLine: read a line into s, return length */
int getLine(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
