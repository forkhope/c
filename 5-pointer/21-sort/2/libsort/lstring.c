#include <stdlib.h>		/* 声明 atof() 函数 */

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
