#ifndef LIBTREE_H
#define LIBTREE_H

/* C provides a facility called typedef for creating new data type names.
 * Notice that the type being declared in a typedef appears in the position
 * of a variable name, not right after the word typedef. Syntacitically,
 * typedef is like the storage classes extern, static, etc. We have used
 * capitalized names for typedefs, to make them stand out.
 * 比较 char *String; 和 typedef char *String; 前者定义了一个变量String,该
 * 变量是char *类型的指针;后者定义了一种新的数据类型,该数据类型是char *类型
 * typedef 语句去掉 typedef 关键字后,和一般的变量定义语句是完全一样,typedef
 * 将标识符从变量变为数据类型,即标识符代表的意思变了.又比如下面的例子:
 * typedef int (*PFI) (char *, char *); 如果去掉typedef, 则该语句定一个函数
 * 指针PFI--for "pointer to function (of two char *arguments) returning int"
 * 加上typedef后,标识符PFI 表示一种数据类型,这种数据类型可以定义函数指针.
 * 看一个typedef语句,关键是看去掉typedef后,标识符是什么类型的变量,则加上
 * typedef后,该标识符就表示什么类型的数据类型.
 */
typedef struct tnode *Treeptr;

typedef struct tnode {		/* the tree node: */
	char *word;				/* pointer to the text */
	int count;				/* number of occurrences */
	struct tnode *left;		/* left child */
	struct tnode *right;	/* right child */
} Treenode;

extern Treeptr talloc(void);
extern Treeptr addtree(Treeptr , char *);
extern void treeprint(Treeptr);

extern int getword(char *, int);

#endif	/* LIBTREE_H */
