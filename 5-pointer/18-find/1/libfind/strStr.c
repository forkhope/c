#include <stdio.h>
#include "lstring.h"

/* strStr: finds the first occurrence of the substring needle in the 
 * string haystack. The terminating '\0' characters are not compared.
 */
char *strStr(const char *haystack, const char *needle)
{
	int len;

	if (*needle != '\0') {
		len = strLen(needle);
		while (strnCmp(haystack, needle, len) != 0) {
			if (*haystack++ == '\0')
				return NULL;
		}
	}
	/* 下面的返回语句需要进行强制类型转换,否则 gcc -Wall 选项会报警,
	 * 说是丢失原先的质量,这里指的haystack指针原本的const属性会丢失.
	 */
	return (char *)haystack;
}
