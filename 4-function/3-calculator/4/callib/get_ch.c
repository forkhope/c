#include <stdio.h>

extern int str_len(const char s[]);

#define BUFSIZE	100		/* 缓冲区大小 */
char buf[BUFSIZE];		/* 缓冲区 */
int bufp = 0;			/* 指向缓冲区下一个可用的位置 */

int get_ch(void)		/* get a (possibly pushed-back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void unget_ch(const int c)	/* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("unget_ch: too many characters\n");
	else
		buf[bufp++] = c;
}

/* 上面的 get_ch() 和 unget_ch() 如同栈一样操作, unget_ch() 将新字符存入
 * 缓冲区后面的位置, get_ch() 则从后往前取出字符. 注意这一点, ungets()
 * 函数应该从字符串的末尾开始存入,这样, get_ch() 取出的顺序才是正确的.
 *
 * ungets(): 将 s "回读" 到缓冲区中,"回读"的顺序和字符串原有顺序相反.
 */
void ungets(const char s[])
{
	int i ;
	/* 假设传入的字符数组中存有字符串"tian",则str_len(s)返回4,而s[4]=='\0'
	 * C 语言中,对字符串的操作时默认字符串会以'\0'结尾,为了保证存入的字符串
	 * 的完整,这里会将'\0'字符一起"回读"到缓冲区中.保存字符串到字符数组中时
	 * 把'\0'字符一起存入,可以避免以后使用该字符数组时出错.
	 */
	for (i = str_len(s); i >= 0; --i)
		unget_ch(s[i]);
}
