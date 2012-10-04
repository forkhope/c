#include <stdio.h>
#include "libpoint.h"

void drawborder(int left, int right, int height)
{
	while (--height > 0) {
		setcol(left);
		printf("+");
		setcol(right - left - 1);
		printf("+");
		printf("\n");
	}
}
