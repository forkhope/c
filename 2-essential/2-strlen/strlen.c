#include <stdio.h>

int strLen(char s[]);

/* Technically, a string constant is an array of characters. The internal
 * representation of a string has a null character '\0' at the end, so the
 * physical storage required is one more than the number of characters 
 * written between the quotes.在C语言中,字符串常量就等同于字符数组
 */
int main()
{
	printf("length of \"tian\" is %d\n", strLen("tian"));
	printf("length of \"\" is %d\n", strLen(""));

	/* A character constant is an integer, written as one character within
	 * single quotes, such as 'x'. The value of a character constant is the
	 * numeric value of the chracter in the machine's character set.例如,在
	 * ascii码中,'0'的值是48,转换位16进制是0x30.注意,在ascii码中,0这个值代表
	 * 的是空字符,即没有任何意义,然后在C语言中,使用这个值来作为字符串的结尾
	 * 字符,并用转义字符'\0'来表示它,也就是'\0'=0,要注意区分0和'0'的不同之处
	 */
	printf("字符常量'0' = %d\n", '0');
	printf("字符常量'\\0' = %d\n", '\0');

	char s[5] = {'1', '2', '3', '4', 0}; // 这里0可以作为字符数组的终止字符
	printf("%s\n", s);	// 将会打印出 1234 和 回车.
	s[3] = 0;
	s[4] = '5';
	printf("%s\n", s);	// 将会打印出 123 和 回车,后面的s[4]会被忽略.
	s[2] = '\0';		// 使用 '\0' 来作为终止字符,会更清晰,更符合习惯.
	printf("%s\n", s);	// 将会打印出 12 和 回车.
	
	/* 注意 'x' 和 "x" 的区别, 'x' 的值是一个整数,对应ascii码中字符x的编号,
	 * 而 "x" 是一个字符串,该字符串由字符 x 和 终止字符'\0'组成,占两个字节.
	 */
	int i = 'x';
	printf("'x' = %d, and %d in ascii is %c\n", i, 120, i);

	/* C语言在编译时,可以将多个相邻字符串常量连接起来 */
	printf("%s\n", "Hello, " "I am " "lixianyi");
	return 0;
}

/* strLen: return length of s */
int strLen(char s[])
{
	int i = 0;
	while (s[i] != '\0')
		++i;
	return i;
}
