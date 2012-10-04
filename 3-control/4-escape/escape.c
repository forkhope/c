/* Write a function escape(s, t) that converts characters like newline and
 * tab into visible escape sequences like \n and \t as it copies the string
 * t to s. Use a switch. Write a function for the other direction as well,
 * converting escape sequences into the real characters.
 */

/* escape() 函数 */
void escape(char s[], const char t[])
{
	int  i, j;

	for (i = 0, j = 0; t[i] != '\0'; ++i) {
		switch (t[i]) {
			case '\n':
				s[j++] = '\\';
				s[j++] = 'n';
				break;
			case '\t':
				s[j++] = '\\';
				s[j++] = 't';
				break;
			default:
				s[j++] = t[i];
				break;
		}
	}
	s[j] = '\0';
}

/* unescape() 函数 */
void unescape(char s[], const char t[])
{
	int i, j;

	for (i = 0, j = 0; t[i] != '\0'; ++i) {
		switch (t[i]) {
			case '\\':
				switch (t[++i]) {
					case 't':
						s[j++] = '\t';
						break;
					case 'n':
						s[j++] = '\n';
						break;
					default:
						s[j++] = '\\';
						s[j++] = t[i];
						break;
				}
				break;
			default:
				s[j++] = t[i];
				break;
		}
	}
	s[j] = '\0';
}
