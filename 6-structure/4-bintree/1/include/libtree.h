#ifndef LIBTREE_H
#define LIBTREE_H

struct tnode {		/* the tree node: */
	char *word;				/* pointer to the text */
	int count;				/* number of occurrences */
	struct tnode *left;		/* left child */
	struct tnode *right;	/* right child */
};

extern struct tnode *talloc(void);
extern struct tnode *addtree(struct tnode *, char *);
extern void treeprint(struct tnode *);

extern int getword(char *, int);

#endif	/* LIBTREE_H */
