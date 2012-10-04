/* Write a function htoi(s), which converts a string of hexadecimal digits
 * (including an optional 0x or 0X) into its equivalent interger value. The
 * allowable digits are 0 through 9, a through f, and A through F.
 */
unsigned int htoi(const char s[])
{
	unsigned int i, n;

	i = 0;
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
		i += 2;
	
	n = 0;
	while (s[i] != '\0') {
		if (s[i] >= '0' && s[i] <= '9')
			n = 16 * n + (s[i] - '0');
		else if (s[i] >= 'A' && s[i] <= 'F')
			n = 16 * n + (s[i] - 'A' + 10);
		else if (s[i] >= 'a' && s[i] <= 'f')
			n = 16 * n + (s[i] - 'a' + 10);
		else {	/* 此时所给字符串中包含不合要求的字符,转换停止,返回0 */
			return 0;
		}
		++i;
	}
	return n;
}
