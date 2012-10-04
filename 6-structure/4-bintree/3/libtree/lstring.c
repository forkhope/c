#include <stdlib.h>		/* 声明 malloc() 函数 */

/* strLen: return length of s */
unsigned int strLen(const char *s)
{
	const char *p;

	for (p = s; *p != '\0'; ++p)
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

/* strCmp: return <0 if t < s; 0 if t == s; >0 if t > s */
int strCmp(const char *t, const char *s)
{
	for ( ; *t == *s; ++t, ++s)
		if (*t == '\0')
			return 0;
	return *t - *s;
}

/* strDup: make a duplicate of s; Memory for the new string is obtained
 * with malloc(), and can be freed with free().
 */
char *strDup(const char *s)
{
	char *p;

	p = (char *)malloc(strLen(s) + 1);	/* +1 for '\0' */
	if (p != NULL)
		strCpy(p, s);
	return p;
}
