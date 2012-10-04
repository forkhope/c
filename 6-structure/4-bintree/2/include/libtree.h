#ifndef LIBTREE_H
#define LIBTREE_H

struct wordlist {
	struct wordlist *next;	/* the next wordlist */
	int linenum;			/* the line number on which word occurs */
};

struct tnode {			/* the tree node: */
	char *word;				/* pointer to the text */
	struct wordlist *first;	/* the first node of repeated word */
	struct tnode *left;		/* left child */
	struct tnode *right;	/* right child */
};

extern struct tnode *talloc(void);
extern struct tnode *addtree(struct tnode *, char *, int linenum);
extern void treeprint(struct tnode *);
extern struct wordlist *addlist(int);
extern void listprint(struct wordlist *);

extern int getword(char *, int);
extern char *noiseword(const char *word);

#endif	/* LIBTREE_H */
