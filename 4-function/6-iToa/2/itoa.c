/* Adapt the ideas of printd to write a recursive version of itoa; that
 * is, convert an integer into a string by calling a recursive routine.
 * 这个 itoa() 函数将返回这个整型值,该值保存下一个可用的数组下标.
 */
int itoa(int n, char s[])
{
	int i = 0;

	if (n < 0) {
		s[i++] = '-';
		i = itoa(-n, s+1);
		s[i+1] = '\0';
		return i;
	}
	if (n / 10)
		i = itoa(n / 10, s);
	s[i++] = n % 10 + '0';
	s[i] = '\0';
	return i;
}
