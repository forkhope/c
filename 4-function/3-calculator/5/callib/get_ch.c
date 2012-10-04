#include <stdio.h>

extern int str_len(const char s[]);

static int ch = -1;	/* ASCII码表中的字符值都大于或等于0,使用-1不会混淆 */

int get_ch(void)		/* get a (possibly pushed-back) character */
{
	int ret;
	if (ch != -1) {
		ret = ch;
		ch = -1;
	}
	else
		ret = getchar();
	return ret;
}

void unget_ch(const int c)	/* push character back on input */
{
	/* 当存入的字符还没有被取走之前,不保存其他的值 */
	if (ch != -1)
		printf("unget_ch: too many characters\n");
	else
		ch = c;
}

/* ungets: 将 s "回读" 到缓冲区中,"回读"的顺序和字符串原有顺序相反 */
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
