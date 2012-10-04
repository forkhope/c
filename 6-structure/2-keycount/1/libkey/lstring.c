/* strcmp: return <0 if dest < src, 0 if dest = src, >0 if dest > src */
int strcmp(const char *dest, const char *src)
{
	for ( ; *dest == *src; ++dest, ++src)
		if (*dest == '\0')
			return 0;
	return *dest - *src;
}
