#include <ctype.h>

/* 使用指针代替数组下标,重写 htoi() 函数 */
unsigned int htoi(const char *s)
{
	int n;

	while (isspace(*s))
		++s;
	if (*s == '0' && (*(s+1) == 'X' || *(s+1) == 'x'))
		s += 2;
	n = 0;
	while (*s != '\0') {
		if (isdigit(*s))
			n = 16 * n + (*s - '0');
		else if (*s >= 'A' && *s <= 'F')
			n = 16 * n + (*s - 'A' + 10);
		else if (*s >= 'a' && *s <= 'f')
			n = 16 * n + (*s - 'a' + 10);
		else	/* 此时所给的字符串中包含不合要求的字符,停止转换,返回0 */
			return 0;
		++s;
	}
	return n;
}
