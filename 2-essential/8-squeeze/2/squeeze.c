/* Write an alternative version of squeeze(s1, s2) that deletes each 
 * character in s1 that matches any character in the string s2.
 */
void squeeze(char s1[], const char s2[])
{
	int i, j, k;

	for (i = 0, k = 0; s1[i] != '\0'; ++i) {
		for (j = 0; s1[i] != s2[j] && s2[j] != '\0'; ++j)
			;
		/* 当 s2[j] == '\0'时,表明一直遍历s2[]到结尾,都没有找到s1[i]字符,即
		 * s1[i]字符不在s2[]里面.这时,保留s1[i]字符;否则不保留s1[i]字符.
		 */
		if (s2[j] == '\0')
			s1[k++] = s1[i];
	}
	s1[k] = '\0';
}
