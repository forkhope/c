#include <stdio.h>

/* echo command-line arguments; 2nd version */
int main(int argc, char *argv[])
{
	/* Since argv is a pointer to an array of pointers, we can manipulate
	 * the pointer rather than index the array. This next variant is based
	 * ont incrementing argv, which is a pointer to pointer to char, while
	 * argc is counted down:
	 */
	while (--argc > 0)
		printf((argc > 1) ? "%s " : "%s", *++argv);
		/* printf("%s%s", *++argv, (argc > 1) ? " " : ""); */
	printf("\n");
	return 0;
}
