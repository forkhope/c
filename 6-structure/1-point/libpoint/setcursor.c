#include <stdio.h>

void setcol(int col)
{
	while (col-- > 0)
		printf(" ");
}

void setrow(int row)
{
	while (row-- > 0)
		printf("\n");
}

void setcursor(int posx, int posy)
{
	setrow(posy);
	setcol(posx);
}
