#include <stdio.h>

#define ALLOCSIZE	10000			/* 可用存储空间大小 */
static char allocbuf[ALLOCSIZE];	/* 存储空间 */
static char *allocp = allocbuf;		/* 指向存储空间未分配的首字符 */

char *alloc(const int n)
{
	if (allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp - n;	/* old allocp */
	}
	else
		return NULL;
}

void afree(const char *p)
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = (char *)p;
}
