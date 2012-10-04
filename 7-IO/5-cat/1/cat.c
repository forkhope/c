#include <stdio.h>

/* cat: concatenate files, version 1. If there are command-line arguments,
 * they are interpreted as filenames, and processed in order. If there are
 * no arguments, the standard input is processed.
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	void filecopy(FILE *, FILE *);

	/* stdin, stdout, and stderr 都是 FILE *类型的常量指针,分别关联标准输入
	 * 标准输出,标准错误输出.
	 */
	if (argc == 1)	/* not args; copy standard input */
		filecopy(stdin, stdout);
	else
		while (--argc > 0)
			if ((fp = fopen(*++argv, "r")) == NULL) {
				printf("cat: can't open %s\n", *argv);
				return 1;
			}
			else {
				filecopy(fp, stdout);
				fclose(fp);
			}
	return 0;
}

/* filecopy: copy file ifp to file ofp */
void filecopy(FILE *ifp, FILE *ofp)
{
	int c;

	while ((c = getc(ifp)) != EOF)
		putc(c, ofp);
}
