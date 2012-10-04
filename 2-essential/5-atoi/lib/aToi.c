/* aToi : convert the string s of digits into its numeric equivalent */
int aToi(char s[])
{
	int i, n;

	n = 0;
	/* The expression s[i] - '0' gives the numeric value of the character
	 * stored in s[i], because the values of '0', '1' ... form a contiguous
	 * increasing sequence. 这里for循环的终止条件是s[i]>='0' && s[i]<='9',
	 * 而不是s[i] != '\0',因为aToi()函数是将数字字符串转化为整数,如果字符串
	 * 中出现不是数字的字符,就停止转换.(不考虑十六进制的情况,忽略0x或0X字符)
	 */
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}
