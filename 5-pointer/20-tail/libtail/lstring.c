/* strCpy: copy src to dest, pointer version */
char *strCpy(char *dest, const char *src)
{
	char *p;

	p = dest;
	while ((*p++ = *src++) != '\0')
		;
	return dest;
}
