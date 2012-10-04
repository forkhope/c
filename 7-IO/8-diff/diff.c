#include <stdio.h>
#include <string.h>

#define MAXLINES 1000	/* 读取的行的最大字符数 */
char line1[MAXLINES], line2[MAXLINES];

void printdiff(char *line1, char *line2, int linenum);

/* Write a program to compare two files, printing the first line 
 * where they differ.
 */
int main(int argc, char *argv[])
{
	FILE *fp1, *fp2;
	char *ptr1, *ptr2;
	int linenum;

	if (argc != 3) {
		printf("./diff file1, file2\n");
		return 2;
	}
	if ((fp1 = fopen(argv[1], "r")) == NULL) {
		printf("./diff: can't open %s\n", argv[1]);
		return 1;
	}
	if ((fp2 = fopen(argv[2], "r")) == NULL) {
		printf("./diff: can't open %s\n", argv[2]);
		return 1;
	}
	linenum = 0;	/* 开始比较之前,将当前行号置为 0 */
	ptr1 = fgets(line1, MAXLINES, fp1);
	ptr2 = fgets(line2, MAXLINES, fp2);
	while (ptr1 != NULL && ptr2 != NULL) {
		++linenum;
		if (strncmp(line1, line2, MAXLINES) != 0) {
			printdiff(line1, line2, linenum);
			break;
		}
		ptr1 = fgets(line1, MAXLINES, fp1);
		ptr2 = fgets(line2, MAXLINES, fp2);
	}
	if (ptr1 != NULL && ptr2 == NULL)
		printdiff(line1, "EOF\n", linenum);
	else if (ptr1 == NULL && ptr2 != NULL)
		printdiff("EOF\n", line2, linenum);
	else if (ptr1 == NULL && ptr2 == NULL)
		printf("They are the same\n");
	fclose(fp1);
	fclose(fp2);
	return 0;
}

void printdiff(char *line1, char *line2, int linenum)
{
	printf("The different line number is %d\n", linenum);
	printf("< %s---\n> %s", line1, line2);
}
