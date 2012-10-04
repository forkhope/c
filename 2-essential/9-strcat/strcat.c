/* strCat: concatenate t to end of s; s must be big enough.
 * Here, strCat() returns no value; the stanary library version
 * returns a pointer to the resulting string.
 */
void strCat(char s[], const char t[])
{
	int i, j;

	i = j = 0;
	while (s[i] != '\0') /* find end of s */
		++i;
	/* 下面的循环不要写为如下的形式:
	 * for (j = 0; t[j] != '\0'; ++j, ++i)
	 *    s[i] = t[j];
	 * s[i] = '\0';
	 * 这样写虽然没错,但是不够简洁、紧凑;在书中主要采用下面的写法,作为一种
	 * 学习的成果,复制一个字符串到另一个字符串时,要习惯写成下面的形式.
	 */
	while ((s[i++] = t[j++]) != '\0') /* copy t */
		;
}
