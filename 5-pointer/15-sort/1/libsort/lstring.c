/* strCpy: copy t to s; pointer version 3 */
char *strCpy(char *dest, const char *src)
{
	char *p;

	p = dest;
	while ((*p++ = *src++))
		;
	return dest;
}

/* strCmp: return <0 if s < t, 0 if s==t, >0 if s > t */
int strCmp(const char *dest, const char *src)
{
	for ( ; *dest == *src; ++dest, ++src)
		if (*dest == '\0')
			return 0;
	return (*dest - *src);
}
