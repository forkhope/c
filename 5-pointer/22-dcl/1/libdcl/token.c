#include <string.h>
#include <ctype.h>
#include "getch.h"
#define MAXLEN	100

enum { NAME, PARENS, BRACKETS };

int tokentype;			/* type of last token */
char token[MAXLEN];		/* last token string */
char name[MAXLEN];		/* identifier name */
char datatype[MAXLEN];	/* data type = char, int, etc. */
char out[1000];

/* The function gettoken skips blanks and tabs, then finds the next token
 * in the input; a "token" is a name, a pair of parentheses, a pair of 
 * brackets perhaps including a number, or any othen single character.
 */
int gettoken(void)		/* return next token */
{
	int c;
	char *p = token;

	/* 如果要对整行字符串进行处理,则使用getline()函数来获取一行字符串;
	 * 如果要对单词或者单个字符进行处理,则使用getch()函数来获取单词或字符,
	 * 程序应根据要处理的单元(行、单词、字符)不同,而选用不同的读取函数.
	 */
	while ((c = getch()) == ' ' || c == '\t')
		;
	if (c == '(') {
		if ((c = getch()) == ')') {
			strcpy(token, "()");
			return tokentype = PARENS;
		}
		else {
			ungetch(c);
			return tokentype = '(';
		}
	}
	else if (c == '[') {
		for (*p++ = c; (*p++ = getch()) != ']'; )
			;
		*p = '\0';
		return tokentype = BRACKETS;
	}
	else if (isalpha(c)) {
		for (*p++ = c; isalnum(c = getch()); )
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	}
	else
		return tokentype = c;
}
