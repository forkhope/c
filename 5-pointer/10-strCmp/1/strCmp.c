/* strCmp: return <0 if s < t, o if s == t, >0 if s > t.
 * const char *s表示:指针s指向的字符是常量,不能改变,但s可以被改变,它是变量
 */
int strCmp(const char *s, const char *t)
{
	int i;

	for (i = 0; s[i] == t[i]; ++i) {
		/* 下面的if 语句不需要判断 t[i] 是否等于 '\0'.体会一下就明白 */
		if (s[i] == '\0')
			return 0;
	}
	return s[i] - t[i];
}
