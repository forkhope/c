#ifndef LIBPOINT_H
#define LIBPOINT_H

/* A structure is a collection of one or more variables, possibly of
 * different types, grouped together under a single name for convenient
 * handling.
 */
struct point {
	int x;
	int y;
};

struct rect {
	struct point p1;
	struct point p2;
};

extern void setcol(int col);
extern void setrow(int row);
extern void setcursor(int posx, int posy);

extern struct point makepoint(int x, int y);

extern void drawrow(int left, int right);
extern void drawborder(int left, int right, int height);
extern void drawrect(struct rect r);

#endif	/* LIBPOINT_H */
