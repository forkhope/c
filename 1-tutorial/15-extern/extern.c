#include<stdio.h>

#define MAXLINE	1000	/* maximum input line length */

int max;				/* maximum length seen so far */
char line[MAXLINE];		/* current input line */
char longest[MAXLINE];	/* longest line saved here */

int getLine(void);
void copy(void);

/* print longest input line; specialized version */
int main(void)
{
	int len;			/* current input line length */
	/* 函数要使用一个外部变量,必须先声明它,可以用 extern 关键字来显式声明,
	 * 也可以从上下文中隐式声明.下面都使用 extern 来显式声明,但是由于这些
	 * 变量和使用它们的函数都定义在同一个源文件里面,可以不声明,直接使用.
	 */
	extern int max;
	extern char longest[];	

	max = 0;
	while((len = getLine()) > 0)
		if (len > max) {
			max = len;
			copy();
		}
	if (max > 0)		/* there was a line */
		printf("%s", longest);
	return 0;
}

/* getLine: specialized version */
int getLine(void)
{
	int c, i;
	extern char line[];

	for (i = 0; i < MAXLINE-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n') 
		line[i++] = c;
	line[i] = '\0';
	return i;
}

/* copy: specialized version */
void copy(void)
{
	int i;
	extern char line[], longest[];

	i = 0;
	while ((longest[i] = line[i]) != '\0')
		++i;
}
