#include <stdio.h>
#include "libpoint.h"

void drawrect(struct rect r)
{
	setrow(r.p1.y);
	drawrow(r.p1.x, r.p2.x);
	drawborder(r.p1.x, r.p2.x, r.p2.y - r.p1.y);
	drawrow(r.p1.x, r.p2.x);
}
