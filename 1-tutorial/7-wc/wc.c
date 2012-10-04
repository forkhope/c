#include<stdio.h>

/* 用宏来取代魔法数字是一个良好的编程习惯,要坚持这种写法 */
#define IN	1	/* inside a word */
#define OUT	0	/* outside a word */

/* count lines, words, and characters in input */
int main()
{
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF) {
		++nc;		// 字符数加 1
		if (c == '\n')
			++nl;	// 行数加 1
		/* 在统计词数时,词数可以加1的情况是:当前字符不是空格,不是列表符,不是
		 * 回车,且上一个字符是空格,或者是列表符,或者是回车.程序中使用state
		 * 变量的不同取值来标识上一个字符是否空格,列表符或者回车.注意领会.
		 */
		if (c == ' ' || c == '\t' || c == '\n') //==的优先级大于||,不加括号
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;	// 词数加 1
		}
	}
	printf("lines=%d, words=%d, characters=%d\n", nl, nw, nc);
	return 0;
}
