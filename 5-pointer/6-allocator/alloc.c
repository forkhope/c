/* Let us illustrate by writing a rudimentary storage allocator. There are
 * two routines. The first, alloc(n), returns a pointer to n consecutive
 * character positions, which can be used by the caller of alloc for 
 * storing characters, The second, afree(p), releases the storage thus
 * acquired so it can be reused later.
 */
#define ALLOCSIZE			10000	/* size of available space */
static char allocbuf[ALLOCSIZE];	/* storage for alloc */
/* This could also have been written: static char *allocp = &allocbuf[0];
 * since the array name is the address of the zeroth element.
 */
static char *allocp = allocbuf;		/* next free position */

char *alloc(const int n)	/* return pointer to n characters */
{
	/* If the request can be satisfied, alloc returns a pointer to the
	 * beginning of a block of characters.
	 */
	if (allocbuf + ALLOCSIZE - allocp >= n) {	/* it fits */
		allocp += n;
		return allocp - n;	/* old p */
	}
	/* If not, alloc must return some signal that there is no space left.
	 * C guarantees that zero is never a valid address for data, so a 
	 * return value of zero can be used to signal an abnormal event, in
	 * this case no space. Pointers and integers are not interchangeable.
	 * Zero is the sole exception: the constant zero may be assigned to a
	 * pointer, and a pointer may be compared with the constant zero. The
	 * symbolic constant NULL is often used in place of zero.
	 */
	else					/* not enough room */
		return 0;			/* 关于返回 0 的说明见上面的注释 */

	/* The valid pointer operations are assignment of pointers of the same
	 * type, adding or subtracting a pointer and an integer, subtracting or
	 * comparing two pointers to members of the same array, and assigning 
	 * or comparing to zero. All other pointer arithmetic is illegal. It is
	 * not legal to add two pointers, or to multiply or divide or shift or
	 * mask them, or to add float or double to them, or even, except for
	 * void *, to assign an pointer of one type to a pointer of another 
	 * type without a case.
	 */
}

void afree(char *p)	/* free storage pointed to by p */
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}
