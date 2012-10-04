#include <stdio.h>
#include <stdlib.h>	/* 声明 exit() 函数 */

/* cat: concatenate files, version 2. If there are command-line arguments,
 * they are interpreted as filenames, and processed in order. If there are
 * no arguments, the standard input is processed.
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	void filecopy(FILE *, FILE *);
	char *prog = argv[0];	/* program name for errors */

	if (argc == 1) 	/* no args; cat from standard input */
		filecopy(stdin, stdout);
	else 
		while (--argc > 0)
			if ((fp = fopen(*++argv, "r")) == NULL) {
				fprintf(stderr, "%s can't open %s\n", prog, *argv);
				exit(1);
			}
			else {
				filecopy(fp, stdout);
				fclose(fp);
			}

	/* The function ferror returns non-zero if an error occurred on the
	 * stream fp. 下面的语句检查是否在使用标准输出时遇到错误.
	 */
	if (ferror(stdout)) {
		fprintf(stderr, "%s: error writing stdout\n", prog);
		exit(2);
	}
	/* The library function exit, which terminates program execution when
	 * it is called. The argument of exit is available to whatever process
	 * called this one, so the success or failure of the program can be
	 * tested by another program that uses this one as a sub-process.
	 */
	exit(0);
}

void filecopy(FILE *ifp, FILE *ofp)
{
	int c;

	while ((c = getc(ifp)) != EOF)
		putc(c, ofp);
}
