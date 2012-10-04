#include <stdio.h>
#include <unistd.h>

/* getChar: simple buffered version. This version of getChar does input
 * in big chunks, and hands out the characters one at a time.
 */
int getChar(void)
{
	static char buf[BUFSIZ];
	static char *bufp = buf;
	static int n = 0;

	if (n == 0) {	/* buffer is empty */
		n = read(0, buf, sizeof buf);
		bufp = buf;
	}
	return (--n >= 0) ? (unsigned char)*bufp++ : EOF;
}
