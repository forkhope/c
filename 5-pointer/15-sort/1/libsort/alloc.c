#include <stdio.h>

#define ALLOCSIZE	10000			/* 可以分配的空间大小 */
static char allocbuf[ALLOCSIZE];	/* 可以分配的空间 */
static char *allocp = allocbuf;		/* 指向当前还没分配的空间 */

char *alloc(const int size)	/* return pointer to n characters or NULL */
{
	if (allocbuf + ALLOCSIZE - allocp >= size) { /* it fits */
		allocp += size;
		return (allocp - size);		/* old p */
	}
	else				/* not enough room */
		return NULL;
}

void afree(char *p)		/* free storage pointed to by p */
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}
