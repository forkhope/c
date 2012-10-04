/* Write a pointer version of the function strcat that we showed int
 * Chapter 2: strcat(s, t) copies the string t to the end of s.
 */
void strCat(char *s, const char *t)
{
	while (*s != '\0')
		++s;
	while ((*s++ = *t++))	/* gcc编译器建议用括号将赋值语句括起来 */
		;
}
