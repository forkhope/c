#include <stdio.h>
#include <ctype.h>
#include "libtree.h"
#define MAXWORD 100	

/* Write a program that prints the distinct words in its input sorted into
 * decreasing order of frequency of occurrence. Precede each word by its
 * count.
 */
int main(void)
{
	struct tnode *root, *newroot;
	char word[MAXWORD];

	/* 我在写代码时,忽略了下面一句,编译时没有问题,但是运行时会报段错误;
	 * 因为 addtree() 函数里面会根据传入的指针是否为 NULL,来决定是否要分配
	 * 一块新的内存.由于忽略了下面一句, root 不等于 NULL,导致没有给 root
	 * 分配新的内存;然而, root 指向的内存此时未知,导致内存访问出错,段错误
	 */
	root = newroot = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word);
	//treeprint(root);
	newroot = resorttree(newroot, root);	// 按照单词次数重新排序 
	treeprint(newroot);
	return 0;
}
