/* strCpy: copy t to s; pointer version */
void strCpy(char *s, char *t)
{
	int i;

	i = 0;
	while ((*s = *t) != '\0') {
		++s;
		++t;
	}
}
