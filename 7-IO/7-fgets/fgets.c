#include <stdio.h>
#include <string.h>
#define MAXLINES 1000	/* 输入行的最大长度 */

char *Fgets(char *s, int size, FILE *iop);
int Fputs(const char *s, FILE *iop);
int getLine(char *line, int max);

/* 实现 C标准库函数 fgets() 和 fputs(),为了防止重名,程序中使用 Fgets() 和
 * Fputs() 来表示这两个函数.
 * char *fgets(char *line, int maxline, FILE *fp);
 * fgets reads the next input line(including the newline) from file fp into
 * the character array line; at most maxline-1 characters will be read. The
 * resulting line is terminated with '\0'. Normally fgets returns line; On
 * end of file or error it returns NULL.
 * For output, the function fputs writes a string (which need not contain a
 * newline) to file: 	int fputs(char *line, FILE *fp);
 * It returns EOF if an error occurs, and non-negative otherwise.
 */
int main(void)
{
	char line[MAXLINES];

	Fgets(line, MAXLINES, stdin);	/* 从标准输入获取一行字符串 */
	Fputs(line, stdout);	/* 将获取到的字符串输出到标准输出中 */
	
	getLine(line, MAXLINES);	/* 使用新实现的getLine()函数获取输入行 */	
	Fputs(line, stdout);	/* 输出使用getLine()函数获取的输入行 */

	/* 最后要说的一点是: the library functions gets and puts are similar to
	 * fgets and fputs, but operate on stdin and stdout. gets()函数的原型:
	 * char *gets(char *s); 可以看到,gets()函数没有参数来控制可输入字符个数
	 * 这是个非常危险的函数!!在程序中,严禁使用gets()函数! gcc中如果使用了这
	 * 个函数,会打印出一行警告信息,如下:
	 * /tmp/ccfijC0F.o: In function `main': fgets.c:(.text+0x6f): 
     * warning:the `gets' function is dangerous and should not be used.
	 */
	//gets(line);
	return 0;
}

/* Fgets: get at most n chars from iop */
char *Fgets(char *s, int size, FILE *iop)
{
	register int c;
	register char *cs;

	cs = s;
	while (--size > 0 && (c = getc(iop)) != EOF)
		if ((*cs++ = c) == '\n')
			break;
	*cs = '\0';
	return (c == EOF && cs == s) ? NULL : 0;
}

/* Fputs: put string s on file iop */
int Fputs(const char *s, FILE *iop)
{
	int c;

	while ((c = *s++) != '\0')
		putc(c, iop);
	return ferror(iop) ? EOF : 0;
}

/* It is easy to implement our getline from fgets:
 * getLine: read a line, return length */
int getLine(char *line, int max)
{
	if (Fgets(line, max, stdin) == NULL)
		return 0;
	else
		return strlen(line);
}
