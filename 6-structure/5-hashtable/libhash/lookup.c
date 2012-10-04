#include <stdio.h>
#include "lstring.h"
#include "libhash.h"

/* lookup: look for s in hashtab; 该函数调用hash()函数,由所给字符串得到一个
 * 较小的非负数,使用该非负数作为hash表的数组下标,得到一个指向链表头的指针,
 * 在该链表中查找所给字符串是否存在. If lookup finds the entry already
 * present, it returns a pointer to is; if not, it returns NULL.
 */
struct nlist *lookup(const char *s)
{
	struct nlist *np;

	/* The for loop in this function is the standard idiom for walking
	 * along a linked list:
	 * for (ptr = head; ptr != NULL; ptr = ptr->next)
	 *     ....
	 */
	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strCmp(s, np->name) == 0)
			return np;		/* found */
	return NULL;			/* not found */
}
