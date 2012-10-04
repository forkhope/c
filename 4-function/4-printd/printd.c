#include <stdio.h>

/* printd: print n in decimal.
 * This version can fail on the largest negative number.
 */
void printd(int n)
{
	if (n < 0) {
		putchar('-');
		n = -n;
	}
	if (n / 10)
		printd(n / 10);
	putchar(n % 10 + '0');
}
