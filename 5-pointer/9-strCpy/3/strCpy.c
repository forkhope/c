/* strCpy: copy t to s; pointer version 3 */
void strCpy(char *s, char *t)
{
	/* As the final abbreviation, observe that a comparison against '\0' is
	 * redundant, since the question is merely whether the expression is
	 * zero. 由于 '\0' == 0,而在 C 中, 0 即为 假,所以不需要判断是否等于'\0'
	 */
	while ((*s++ = *t++)) /* gcc编译器建议使用括号将赋值语句括起来 */
		;
}
