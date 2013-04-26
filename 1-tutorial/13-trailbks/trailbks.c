#include<stdio.h>
#define MAXLINE	1000	/* maximum input line length */

int getLine(char line[], int maxline);

/* Remove trailing blanks and tabs from each line of input, and to delete
 * entirely blank lines.
 */
int main()
{
	int len;			/* current line length */
	char line[MAXLINE];	/* current input line */

	while ((len = getLine(line, MAXLINE)) > 0) {
		--len;			/* --len 是为了跳过字符串末尾的 '\n' 字符 */
		while (len > 0 && (line[len] == ' ' || line[len] == '\t')) 
			--len;
		if (len > 0) {	/* len > 0 表明line[]数组中还有其他非空字符 */
			line[++len] = '\n';
			line[++len] = '\0';		/* 用 '\0' 字符标识字符串的末尾 */
			printf("%s", line);
		}
	}
	return 0;
}

// getLine: read a line into s, return length.这里返回的输入行不包括回车字符
int getLine(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	s[i] = '\0';
	return i;
}
