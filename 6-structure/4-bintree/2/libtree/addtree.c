#include <stdio.h>
#include "libtree.h"
#include "lstring.h"

struct tnode *addtree(struct tnode *p, char *w, int linenum)
{
	int cond;
	struct wordlist *newline = NULL;

	if (p == NULL) {		/* a new word arrives */
		p = talloc();
		p->word = strDup(w);
		p->first = addlist(linenum);
		p->left = p->right = NULL;
	}
	else if ((cond = strCmp(w, p->word)) == 0) {
		newline = addlist(linenum);
		newline->next = p->first;
		p->first = newline;
	}
	else if (cond < 0)		/* less than into subtree */
		p->left = addtree(p->left, w, linenum);
	else					/* greater than into subtree */
		p->right = addtree(p->right, w, linenum);
	return p;
}
