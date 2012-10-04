#include<stdio.h>

/* copy input to output, replacing each string of one or more blanks by a
 * single blank. 将一个字符串中多个连续的空格缩短为一个单独的空格.
 */
int main()
{
	int current, previous;

	previous = EOF;	// 将 previous 置为 EOF,避免了匹配任何可能的字符
	while ((current = getchar()) != EOF) {
		/* 判断字符是否可以输出,如果可以就输出,不考虑不可以输出的情况
		 * 可以输出的情况是: 当前字符不是空格,或者当前字符是空格,但是上一个
		 * 字符不是空格,这两种情况都可以输出,都属于不是连续空格的情况.
		 * 不可以输出的情况是: 出现连续空格的时候,即当前字符是空格,上一个
		 * 字符也是空格,这时候,当前的空格字符就被忽略,不进行输出.
		 * 注意这种思考的方式,在出现二选一的时候,只对一种情况进行判断.程序
		 * 中就只考虑了可以输出的情况,这样显得很直接,不受另一个情况的干扰.
		 */
		if (current == ' ')
			if (previous != ' ')
				putchar(current);
		if (current != ' ')
			putchar(current);
		previous = current;
	}
	return 0;
}
