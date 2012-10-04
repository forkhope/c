#include <stdio.h>
#include "getLine.h"
#include "lstring.h"
#define MAXLINE 1000	/* maximum length of input line */

/* find: print lines that match pattern from 1st arg */
int main(int argc, char *argv[])
{
	char line[MAXLINE];
	long lineno = 0;
	int c, except = 0, number = 0, found = 0;

	/* argv作为一个字符指针数组的数组名,则argv是数组首元素的地址,++argv
	 * 是数组首元素的下一个元素的地址,*++argv相当于argv[1],而argv[1]是
	 * 一个指向第一个参数字符串的字符指针,(*++argv)[0]取指针指向的首元素
	 * 假如输入命令是 find -n -x "ould",则(*++argv)[0]正好等于'-'.下面的
	 * 第一个while循环正是通过这种方式来获取命令的选项参数,从而进行操作.
	 */
	while (--argc && (*++argv)[0] == '-') {
		/* 上面提到如果输入命令包含参数,则(*++argv)[0]正好指向参数的第一个
		 * 字符,按照惯例,该字符是'-';此时,argv[0]是一个指向第一个参数字符串
		 * 的字符指针,则++argv[0]指向第一个参数字符串的第二个字符的地址,则
		 * *++argv[0]指向该字符,如果输入命令是 find -n -x "ould",则该字符
		 * 是'n', switch 语句会对取出来的字符进行判断并处理.由于命令参数传
		 * 给main()函数时,是以字符串的形式传入,所以命令参数的末尾会有'\0',
		 * 书中把下面的while循环写为 while (c = *++argv[0]), 这是利用了这
		 * 一点来作为终止条件.当然,写为下面的形式,会显得直观一点.
		 */
		while ((c = *++argv[0]) != '\0')
			switch (c) {
			/* precede each printed line by its line number */
				case 'n':
					number = 1;
					break;
			/* print all the lines except those that match the pattern */
				case 'x':
					except = 1;
					break;
				default:
					printf("error: illegal option %c\n", c);
					argc = 0;
					found = -1;
					break;
			}
	}
	/* 解析完参数选项后,应该还剩下一个参数,那就是要比较的模式字符串pattern,
	 * 如果没有这个参数,则输入的命令不正确,下面会打印出提示字符串.
	 */
	if (argc != 1) 
		printf("Usage: find -x -n pattern\n");
	else
		while (getLine(line, MAXLINE) > 0) {
			++lineno;
			/* 当匹配时,strStr(line, *argv) != NULL为1,若希望打印匹配的
			 * 字符串,则except为0,所以if的判断条件为真,打印出匹配的字符串;
			 * 当不匹配时,strStr(line, *argv) != NULL为0,若希望打印不匹配
			 * 的字符串,则except为1,此时if的判断条件为真,打印不匹配的字符串
			 */
			if ((strStr(line, *argv) != NULL) != except) {
				if (number)
					printf("%ld:", lineno);
				printf("%s", line);
				++found;
			}
		}
	return found;

}
