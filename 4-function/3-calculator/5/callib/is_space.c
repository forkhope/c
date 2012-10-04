/* 判断所给字符是否是 空格、列表符、或者 回车 */
int is_space(const int c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}
