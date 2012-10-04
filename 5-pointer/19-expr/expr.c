#include <stdio.h>
#include "lstack.h"
#include "cType.h"
#include "aTof.h"
#include "lstring.h"

/* Write the program expr, which evaluates a reverse Polish expression from
 * the command line, where each operator or operand is a separate argument.
 * For example, expr 2 3 4 + * , evaluates 2 * (3 + 4).
 * 注意,在输入命令时,由于shell默认会对 '*' 字符进行扩展,所以直接输入
 * expr 2 3 4 + * 会出错,为了避免这种情况,可以抑制shell 对 '*' 的扩展,
 * 即输入 2 3 4 + \*, 使用 \* 进行转义,就不会对 '*' 字符进行扩展.
 */
int main(int argc, char *argv[])
{
	double op2;

	if (argc < 4) {
		printf("Usage expr op1 op2 operator ... \n");
		return 1;	/* main() 函数返回0,表示正常,返回值 >0,表示出错 */
	}
	while (--argc > 0) {
		++argv;
		if (strLen(*argv) == 1 && !is_digit(*argv[0]))
			switch (*argv[0]) {
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
					if (op2 == 0.0)
						printf("error: zero divisor\n");
					else
						push(pop() / op2);
					break;
				default:
					printf("error: unknown command %c", *argv[0]);
					break;
			}
		else
			push(aTof(*argv));
	}
	printf("%.8g\n", pop());
	return 0;
}
