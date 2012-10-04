#include <stdio.h>

/* If a parameter name is preceded by a # in the replacement text, the 
 * comnination will be expanded into a quoted string with the parameter
 * replaced by the actual argument.例如,使用下面的宏iprint(i),则宏替换后为:
 * printf("i" " = %d\n", i),两个字符串连结后变为:printf("i = %d\n", i)
 */
#define iprint(expr) 	printf(#expr " = %d\n", expr)

/* The preprocessor operator ## provides a way to concatenate actual 
 * arguments during macro expansion. If a parameter in the replacement 
 * text is adjacent to a ##, the parameter is replaced by the actual 
 * argument, the ## and surrounding white space are removed, and the
 * result is rescanned. 例如,使用下面的宏paste(name, 1),则宏替换后为:
 * name1,即将两个参数连了一起.
 */
#define paste(front, back) front ## back

int main()
{
	int i;

	i = 389;
	iprint(i);

	i = paste(12, 45);	/* 12 和 45 将会连在一起,变为 1245 */
	iprint(i);			/* 所以,这里打印出来的就是 i = 1245 */
	return 0;
}
