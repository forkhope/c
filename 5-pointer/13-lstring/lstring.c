/* Write versions of the library functions strncpy, strncat, and strncmp,
 * which operate on at most the first n characters of their argument
 * strings. For example, strncpy(s, t, n) copies at most n characters of t
 * to s. Full descriptions are in Appendix B.
 */
char *strnCpy(char *s, const char *t, unsigned int n)
{
	if (n != 0) {
		char *p = s;
		while ((*p++ = *t++) && --n)
			;
		*p = '\0';
	}
	return s;
}

int strnCmp(const char *s, const char *t, unsigned int n)
{
	if (n == 0)
		return 0;
	/* 下面的while循环的判断条件不要写为 while (*s++ == *t++ && --n) 
	 *									 	if (*s == '\0')
	 * 											return 0;
	 * 因为循环里面会判断*s == '\0'是否为真,但是上面的判断条件中,判断完
	 * *s++ == *t++ 后,无论是否为真,s 和 t 都已经加了1,循环体中的 *s 和判断
	 * 之前的 *s 就不再是同一个字符,在处理类似"an"、"xn"的字符串时就会出错
	 * 当*s=='a', *t=='x'时, *s++ == *t++ 为假,且判断完后, *s=='n',*t=='n'
	 * 跳出while循环后,执行return *s - *t,会返回 0,即表示所比较的两个字符串
	 * 相等,但是这两个字符串明显不等,所以上面的while循环的写法是错的.
	 * 这里和上面的 strnCpy() 函数不同, strnCpy() 函数的while循环中没有使用
	 * 到 *s,所以它的判断条件写为((*p++ = *t++) && --n)是可以的,而且,当跳出
	 * while循环时,p 正好指向下一个还没有赋值的位置,这个位置正好可以用来
	 * 填充 '\0' 字符,作为字符串的终止字符.
	 */
	while (*s == *t && --n) {
		if (*s == '\0')
			return 0;
		++s;
		++t;
	}
	return *s - *t;
}

char *strnCat(char *s, const char *t, unsigned int n)
{
	if (n != 0) {
		char *p = s;
		while (*p != '\0')
			++p;
		while ((*p++ = *t++) && --n)
			;
		*p = '\0';
	}
	return s;
}
