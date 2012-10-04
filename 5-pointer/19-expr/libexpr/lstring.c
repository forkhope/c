/* strLen: return length of s */
int strLen(const char *s)
{
	const char *p;

	for (p = s; *p; ++p)
		;
	return p - s;
}
