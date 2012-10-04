/* strCpy: copy t to s; array subscript version */
void strCpy(char *s, char *t)
{
	int i;

	i = 0;
	while ((s[i] = t[i]) != '\0')
		++i;
}
