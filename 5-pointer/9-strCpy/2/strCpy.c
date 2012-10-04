/* strCpy: copy t to s; pointer version 2 */
void strCpy(char *s, char *t)
{
	while ((*s++ = *t++) != '\0')
		;
}
