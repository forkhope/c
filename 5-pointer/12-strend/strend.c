/* Write the function strend(s, t), which returns 1 if the string t
 * occurs at the end of string s, and zero otherwise.
 */
static int strLen(const char *s);

int strend(const char *s, const char *t)
{
	int slen, tlen;

	slen = strLen(s);
	tlen = strLen(t);
	if (slen < tlen)
		return 0;
	for (s += slen - tlen; *s == *t; ++s, ++t)
		if (*t == '\0')
			return 1;
	return 0;
}

static int strLen(const char *s)
{
	const char *p;

	for (p = s; *p; ++p)
		;
	return (p - s);
}
