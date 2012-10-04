#include <stdio.h>
#include "lstring.h"

static char *list[] = {
	"a",
	"an",
	"and",
	"be",
	"but",
	"by",
	"he",
	"I",
	"is",
	"it",
	"off",
	"on",
	"she",
	"so",
	"the",
	"they",
	"you"
};
#define NLISTS (sizeof list / sizeof(list[0]))

/* return NULL if this word is not a noise word,
 * or non-NULL if it is a noise word.
 */
char *noiseword(const char *word)
{
	int cond;
	char **low, **high, **mid;

	/* 下面的语句和 low = list; 是等价的; low = &list[0]; 并不是说 low 指向
     * 数组的首地址的首地址;如果要让 low 指向数组的首地址的首地址,应写为:
	 * low = &list; 不能写为 low = &&list[0];
	 */
	low = &list[0];			/* low 指向数组的首元素的地址 */
	high = &list[NLISTS];	/* high 指向数组末尾元素的后一个元素的地址 */

	while (low < high) {
		mid = low + (high - low) / 2;
		if ((cond = strCmp(word, *mid)) < 0)
			high = mid;
		else if (cond > 0)
			low = mid + 1;
		else 
			return *mid;
	}
	return NULL;
}
