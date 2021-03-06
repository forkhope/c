#include <stdio.h>
#include "libtree.h"

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *root)
{
	if (root != NULL) {
		treeprint(root->right);
		printf("%4d %s\n", root->count, root->word);
		treeprint(root->left);
	}
}
