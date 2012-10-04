/* strnCmp: 比较所给两个字符串的前 n 个字符.
 * 如果相等,则返回 0, 否则返回不等的两个字符的差.
 */
int strnCmp(const char *dest, const char *src, unsigned int n)
{
	if (n == 0)
		return 0;
	for ( ; *dest == *src && --n; ++dest, ++src)
		if (*dest == '\0')
			return 0;
	return *dest - *src;
}
