#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>

void error(const char *fmt, ...);
int get(int fd, long pos, char *buf, int n);
long atoL(const char *s);
int atoI(const char *s);

int main(int argc, char *argv[])
{
	int fd, n;
	long pos;
	char buf[BUFSIZ];

	if (argc != 4)
		error("Usage: ./lseek filename pos bytes");
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		error("./lseek: can't open %s", argv[1]);
	pos = atoL(argv[2]);
	n = atoI(argv[3]);
	if (get(fd, pos, buf, n) > 0)
		printf("%s\n", buf);
	else
		error("./lseek: can't read %d bytes from %s", n, argv[1]);
	close(fd);
	return 0;
}

/* error: print an error message and die */
void error(const char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	fprintf(stderr, "error ");
	vfprintf(stderr, fmt, args);
	fprintf(stderr, "\n");
	va_end(args);
	exit(1);
}

/* get: read n bytes from position pos */
int get(int fd, long pos, char *buf, int n)
{
	/* The return value from lseek() is a long that givens the new position
	 * in the file, or -1 if an error occurs.
	 */
	if (lseek(fd, pos, 0) >= 0) 	/* get to pos */
		return read(fd, buf, n);
	else
		return -1;
}

/* atoL: convert a string to an long integer */
long atoL(const char *s)
{
	long n, sign;

	while (isspace(*s))
		++s;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '-' || *s == '+')
		++s;
	for (n = 0; isdigit(*s); ++s)
		n = n * 10 + (*s - '0');
	return sign * n;
}

/* atoI: convert a string to an integer */
int atoI(const char *s)
{
	int n, sign;

	while (isspace(*s))
		++s;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '-' || *s == '+')
		++s;
	for (n = 0; isdigit(*s); ++s)
		n = n * 10 + (*s - '0');
	return sign * n;
}
