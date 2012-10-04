#include <stdio.h>
#include "libpoint.h"
#include "libgetch.h"
#define MAXSIZE	100		/* max size of point */

int main(void)
{
	struct point p1, p2;
	struct rect r;
	int value[4]; /* 一个矩形需要两个点,两个坐标决定一个点,共4个坐标 */
	int i, type;
	char s[MAXSIZE];

	i = 0;
	while ((type = getpoint(s)) != EOF) {
		if (type == NUMBER)
			value[i++] = aToi(s);
		if (i == 4) {
			i = 0;
			p1 = makepoint(value[0], value[1]);
			p2 = makepoint(value[2], value[3]);
			r.p1 = p1;
			r.p2 = p2;
			drawrect(r);
		}
	}
	return 0;
}
