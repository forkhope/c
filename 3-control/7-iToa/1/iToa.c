#include <string.h>

/* reverse: reverse string s in place */
void reverse(char s[])
{
	int c, i, j;

	/* 下面j的初始化应该等于 strlen(s)-1, 而不是 strlen(s). 例如:
	 * char s[5]="tian",则strlen(s)等于4,若j=strlen(s),则s[j]=s[4]='\0'
	 * 但程序希望从s[3]='n'开始交换,而不是从s[4]='\0'开始,由此可得.
	 */
	for (i = 0, j = strlen(s)-1; i < j; ++i, --j) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

/* iToa: convert n to characters in s */
void iToa(int n, char s[])
{
	int i, sign;

	if ((sign = n) < 0)		/* record sign */
		n = -n;				/* make n positive */
	i = 0;	
	do {		/* generate digits in reverse order */
		s[i++] = n % 10 + '0';	/* get next digit */
	} while ((n /= 10) > 0);	/* delete it */
	if (sign < 0)
		s[i++] = '-';		/* 如果是负数,则加上负号 */
	s[i] = '\0';
	reverse (s);
}
