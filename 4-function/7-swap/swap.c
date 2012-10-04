#include <stdio.h>

/* Define a macro swap(t, x, y) that interchanges two arguments of type t.
 * (Block structure will help.)
 */
#define swap(t, x, y) \
	do { \
		t c; \
		c = x; \
		x = y; \
		y = c; \
	} while (0)

int main()
{
	int i, j;

	i = 8;
	j = 9;
	printf("Before swap, i = %d, j = %d\n", i, j);
	swap(int, i, j);
	printf("After  swap, i = %d, j = %d\n", i, j);
	return 0;
}
