#include <stdio.h>
#include <stdlib.h>

/* strLen: return length of s */
unsigned int strLen(const char *s)
{
	const char *p;

	for (p = s; *p; ++p)
		;
	return p - s;
}

/* strCmp: return <0 if t < s; 0 if t == s; >0 if t > s */
int strCmp(const char *t, const char *s)
{
	for ( ; *t == *s; ++t, ++s)
		if (*t == '\0')
			return 0;
	return *t - *s;
}

/* strCpy: copy string src to dest */
char *strCpy(char *dest, const char *src)
{
	char *p;

	p = dest;
	while ((*p++ = *src++) != '\0')
		;
	return dest;
}

/* strDup: duplicate a string s to a new string; Memory for the new string 
 * is obtained with malloc, and can be freed with free().
 */
char *strDup(const char *src)
{
	char *p;

	p = (char *)malloc(strLen(src) + 1);
	if (p != NULL)
		strCpy(p, src);
	return p;
}
