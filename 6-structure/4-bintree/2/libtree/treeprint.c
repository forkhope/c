#include <stdio.h>
#include "libtree.h"

/* print nodes of a tree */
void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%12s\t",p->word);
		listprint(p->first);
		treeprint(p->right);
	}
}
