#include <stdio.h>
#include "lstring.h"

/* strStr: finds the first occurrence of the substring t in the string s */
char *strStr(const char *s, const char *t)
{
	int len;
	if (*t != '\0') {
		len = strLen(t);
		while (strnCmp(s, t, len) != 0)
			if (*s++ == '\0')
				return NULL;
	}
	return (char *)s;
}
