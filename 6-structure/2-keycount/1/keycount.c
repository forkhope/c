#include <stdio.h>
#include <ctype.h>
#include "libkey.h"
#define MAXWORD	100		/* 关键字的最大长度 */

/* count C keywords */
int main(void)
{
	char word[MAXWORD];	/* 存放获取的关键字、或者字符 */
	int n;

	while (getword(word, MAXWORD) != EOF) 
		if (isalpha(word[0]))
			if ((n = binsearch(word, keytab, nkeys)) >= 0)
				++keytab[n].count;
	for (n = 0; n < nkeys; ++n)
		if (keytab[n].count > 0)
			printf("%4d %s\n", keytab[n].count, keytab[n].word);
	return 0;
}
