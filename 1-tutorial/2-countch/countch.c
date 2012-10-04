#include<stdio.h>

/* count characters in input */
int main()
{
	/* long nc;
	nc = 0;
	while (getchar() != EOF)
		++nc;
	//long型对应的格式是%ld
	printf("输入的字符个数(包括回车)为: %ld\n",nc); */

	// 另一种写法
	double nc;
	for (nc = 0; getchar() != EOF; ++nc)
		;	// do nothing
	printf("%.0f\n", nc);
	return 0;
}
