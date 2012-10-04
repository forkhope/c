#include <string.h>

/* Write the function strindex(s, t) which returns the position of the
 * rightmost occurrence of t in s, or -1 if there is none.
 */
int strindex(const char s[], const char t[])
{
	int i, j, k, t_len;

	/* 为了避免每次重新执行内层for循环时,都调用strlen()函数,使用变量t_len */
	t_len = strlen(t) - 1;	
	for (i = strlen(s) - 1; i >= 0; --i) {
		for (j = i, k = t_len; k >= 0 && s[j] == t[k]; --j, --k)
			;
		if (k < 0 && t[0] != '\0') /* 保证 t 不是空字符串"" */
			return j+1;
	}
	return -1;
}
