/* 计算字符串的长度 */
int str_len(const char s[])
{
	int i = 0;
	/* 注意,在下面的while循环的判断条件时,不要写成 s[i++] != '\0',这样写会
	 * 出错,因为即使是s[i++] == '\0', i 依然被多加了一次;但是下面的写法不会
	 */
	while (s[i] != '\0')
		++i;
	return i;
}
