#include<stdio.h>

/* count blanks, tabs, and newlines */
int main()
{
	int c, nb, nt, nl;

	nb = nt = nl = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++nb;
		if (c == '\t')
			++nt;
		if (c == '\n')
			++nl;
	}
	printf("空格个数:%d\t列表符个数:%d\t回车个数:%d\n", nb, nt, nl);
	return 0;
}
