#include <stdio.h>
#include <stdlib.h>		/* atof() 函数的头文件 */

#define MAXOP	100
#define NUMBER	'0'
#define MAXLINE	1000
static char line[MAXLINE];
static int line_index;

void push(const double f);
double pop(void);
int get_line(char line[], int lim);
int getop(char s[]);

/* reverse Polish calculator.
 * An alternate organization uses getline to read an entire input line;
 * this makes getch and ungetch unnecessary. Revise the calculator to 
 * use this approach.
 */
int main()
{
	int type;
	double op2;
	char s[MAXOP];
	while (get_line(line, MAXLINE) > 0) {
	/* 使用一个全局变量来指示字符数组中当前读到的位置 */
		line_index = 0;	
		while ((type = getop(s)) != '\0') {
			switch (type) {
				case NUMBER:
					push(atof(s));
					break;
				case '+':
					push(pop() + pop());
					break;
				case '*':
					push(pop() * pop());
					break;
				case '-':
					op2 = pop();
					push(pop() - op2);
					break;
				case '/':
					op2 = pop();
					if (op2 != 0.0)
						push(pop() / op2);
					else
						printf("error: zero divisor\n");
					break;
				case '\n':
					printf("\t%.8g\n", pop());
					break;
				default:
					printf("error: unknown command\n");
					break;
			}
		}
	}
		return 0;
}

#define MAXVAL 	100	/* maximum depth of value stack */
double val[MAXVAL];	/* value stack */
int sp = 0;			/* next free stack position */

/* push: push f onto value stack */
void push(const double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack emtpy\n");
		return 0.0;
	}
}

/* get_line: get line into s, return length */
int get_line(char s[], int lim)
{
	int i, c;

	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

#include <ctype.h>

/* getop: get next character or numeric operand */
int getop(char s[])
{
	int i, c;

	while ((s[0] = c = line[line_index++]) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;	/* not a numeric */
	i = 0;
	if (isdigit(c))	/* collect integer part */
		while (isdigit(s[++i] = c = line[line_index++]))
			;
	if (c == '.')	/* collect fraction part */
		while (isdigit(s[++i] = c = line[line_index++]))
			;
	s[i] = '\0';
	--line_index; /* 由于多读了一个字符,所以将当前读到的位置往前退一步 */
	return NUMBER;
}
