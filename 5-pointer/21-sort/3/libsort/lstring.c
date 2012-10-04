#include <stdlib.h>		/* 声明 atof() 函数 */
#include <ctype.h>		/* 声明 toupper() 函数 */
#include "alloc.h"

/* strLen: return length of s */
int strLen(const char *s)
{
	const char *p;

	for (p = s; *p; ++p)
		;
	return p - s;
}

/* strCpy: copy src to dest */
char *strCpy(char *dest, const char *src)
{
	char *p;

	p = dest;
	while ((*p++ = *src++) != '\0')
		;
	return dest;
}

/* strCmp: return <0 if dest < src, 0 if dest == src, >0 if dest > src */
int strCmp(const char *dest, const char *src)
{
	for ( ; *dest == *src; ++dest, ++src)
		if (*dest == '\0')
			return 0;
	return *dest - *src;
}

/* numcmp: compare dest and src numerically */
int numcmp(const char *dest, const char *src)
{
	double v1, v2;

	v1 = atof(dest);
	v2 = atof(src);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

static void upperstring(char *s)
{
	while (*s != '\0') {
		*s = toupper(*s);
		++s;
	}
}

/* foldcmp: fold upper and lower case together */
int foldcmp(const char *s1, const char *s2)
{
	char *x, *y;
	int i;

	x = alloc(strLen(s1) + 1);
	y = alloc(strLen(s2) + 1);
	strCpy(x, s1);
	strCpy(y, s2);

	upperstring(x);
	upperstring(y);
	i = strCmp(x, y);

	afree(x);
	afree(y);
	return i;
}
