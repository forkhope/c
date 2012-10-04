#include <stdio.h>

#define ALLOCSIZE	10000			/* 可用存储空间的大小 */
static char allocbuf[ALLOCSIZE];	/* 存储空间 */
static char *allocp = allocbuf;		/* 指向存储空间未使用的首字符 */

char *alloc(const int n)	/* return pointer to n characters */
{
	if (allocbuf + ALLOCSIZE - allocp >= n) {	/* it fits */
		allocp += n;
		return allocp - n;	/* old p */
	}
	else
		return NULL;
}

void afree(const char *p)	/* free storage pointed to by p */
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = (char *)p;
}
