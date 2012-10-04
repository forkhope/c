#include <stdio.h>
#include <fcntl.h>		/* 声明 open(), creat() 函数 */
#include <unistd.h>

void filecopy(int from, int to);
void error(const char *fmt, ...);

/* Rewrite the program cat from Chapter 7 using read(), write(), open(), 
 * and close() instead of their standard library equivalengts.
 */
int main(int argc, char *argv[])
{
	int fd;

	if (argc == 1)
		filecopy(0, 1);
	else
		while (--argc > 0)
			if ((fd = open(*++argv, O_RDONLY, 0)) == -1)
				error("cat: can't open %s", *argv);
			else {
				filecopy(fd, 1);
				close(fd);
			}
	return 0;
}

/* filecopy: copy from to to */
void filecopy(int from, int to)
{
	char buf[BUFSIZ];
	int n;

	while ((n = read(from, buf, BUFSIZ)) > 0)
		if ((write(to, buf, n)) != n)
			error("cat: write error on stdout");
}

#include <stdarg.h>
#include <stdlib.h>		/* 声明 exit() 函数 */

/* error: print an error message and die */
void error(const char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	fprintf(stderr, "error: ");
	vfprintf(stderr, fmt, args);
	fprintf(stderr, "\n");
	exit(1);
}
