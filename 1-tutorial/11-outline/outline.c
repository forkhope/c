#include<stdio.h>
#define MAXLINE	1000	/* maximum input line length */

int getLine(char line[], int longest);
void copy(char to[], char from[]);

/* print the longest input line */
int main()
{
	int len;				/* current line length */
	int max;				/* maximum length seen so far */
	char line[MAXLINE];		/* current input line */
	char longest[MAXLINE];	/* longest line saved here */

	max = 0;
	// 下面的 = 优先级 小于 >, 所以赋值语句要用括号括起来.
	while((len = getLine(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0)			/* there was a line */
		printf("%s", longest);
	return 0;
}

/* 书中25页末尾写到: you will often see a short function defined and called
 * only once, just because it clarifies some piece of code.这里提到一种编程
 * 习惯:将一些操作封装到函数中去,这样会显得主函数的代码更紧凑,逻辑更清晰,那
 * 怕函数之中就两三个语句,也要坚持这样做,形成习惯.(虽然我觉得似乎不用这样)
 */

/* getLine: read a line into s, return length */
int getLine(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	/* C风格字符串要求以'\0'结尾,'\0'对应的整型值是0,即 '\0' == 0 为真. */
	s[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;
	
	i = 0;
	/* This condition relies on the fact that its input arguments is 
	 * terminated with a '\0', and copies this character into the output.
	 */
	while ((to[i] = from[i]) != '\0')
		++i;
}
