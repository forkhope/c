#include <stdio.h>
#include "libtree.h"
#include "lstring.h"

/* addtree:增加一颗子树到所给结点、或者所给结点的下面;该子树只有一个结点 */
struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;

	if (p == NULL) {	/* a new word has arrived */
		p = talloc();	/* make a new node */
		p->word = strDup(w);
		p->count = 1;
		p->left = p->right = NULL;
	}
	else if ((cond = strCmp(w, p->word)) == 0)
		++p->count;		/* repeated word */
	else if (cond < 0)	/* less than into left subtree */
		p->left = addtree(p->left, w);
	else				/* greater than into right subtree */
		p->right = addtree(p->right, w);
	return p;
}
