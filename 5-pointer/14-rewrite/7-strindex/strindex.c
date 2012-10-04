/* 使用指针代替数组下标,重写 strindex() 函数 */
int strindex(const char *s, const char *t)
{
	const char *p, *q, *r;

	for (p = s; *p !=  '\0'; ++p) {
		for (q = p, r = t; *r != '\0' && *q == *r; ++q, ++r)
			;
		if (s != r && *r == '\0')
			return (p - s);
	}
	return -1;
}
