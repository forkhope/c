/* 计算字符串的长度 */
int str_len(const char s[])
{
	int i = 0;
	/* 下面的while循环的判断条件不能使用s[i++]!='\0',因为当i==4时,尽管
	 * s[i++]!='\0'为假,跳出while循环,但是i++还是执行了一次,跳出循环后,
	 * i == 5,即i被多加了一次(假设传进来的字符串是 "tian").
	 */
	while (s[i] != '\0')
		++i;
	/* 因为数组下标是从 0 开始数,所以字符串长度会比数组下标多 1,当
	 * s[i] == '\0'时,数组下标刚好多加了一次,所以下面直接返回 i 是正确的.
	 */
	return i;
}
