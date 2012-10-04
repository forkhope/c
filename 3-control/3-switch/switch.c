#include <stdio.h>

/* count digits, white space, others */
int main()
{
	int c, i, nwhite, nother, ndigit[10];

	nwhite =  nother = 0;
	for (i = 0; i < 10; ++i)
		ndigit[i] = 0;
	while ((c = getchar()) != EOF) {
		/* Each case is labeled by one or more integer-valued constants or
		 * constant expressions.Cases and the default can occur in any order
		 * Because cases serve just as labels(如同汇编里的标号,即仅表示一个
		 * 地址), after the code for one case is done, execution falls 
		 * through to the next unless you take explicit action to escape. 
		 * break and return are the most common ways to leave a switch.
		 */
		switch (c) {
			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
				++ndigit[c-'0'];
				break;
			case ' ':
			case '\n':
			case '\t':
				++nwhite;
				break;
			default: /* 即使不是真的需要,也保留default语句,这是个好习惯 */
				++nother;
				break;
		}
	}
	printf("digits =");
	for (i = 0; i < 10; ++i)
		printf(" %d", ndigit[i]);
	printf(", white spaces = %d, others = %d\n", nwhite, nother);
	return 0;
}
