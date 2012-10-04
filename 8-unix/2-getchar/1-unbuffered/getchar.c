#include <unistd.h>
#include <stdio.h>

/* getChar: unbuffered single character input, by reading the standard
 * input one character at a time.
 */
int getChar(void)
{
	char c;

	/* 下面的return语句,我是写为:
	 * return (read(0, &c, 1) == 0) ? EOF : (unsigned char)c;
	 * 相比下面的写法,上面的写法有缺陷.当read()函数遇到错误时,会返回-1,该
	 * 写法不能正确地处理这种情况.由于read()函数返回实际读到的字符个数,下
	 * 面的写法表示:当确实读到了一个字符,就返回该字符的unsigned char类型,
	 * 否则返回EOF,这包括了出错的情况、遇到了EOF的情况.
	 * Casting c to unsigned char in the return statement eliminates any
	 * problem of sign extension.
	 */
	return (read(0, &c, 1) == 1) ? (unsigned char)c : EOF;
}
