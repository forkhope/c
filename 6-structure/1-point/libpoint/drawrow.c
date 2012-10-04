#include <stdio.h>
#include "libpoint.h"

void drawrow(int left, int right)
{
	setcol(left);
	while (left++ <= right)
		printf("=");
	printf("\n");
}
