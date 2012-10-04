#include <stdio.h>
#include <ctype.h>
#include "libtree.h"
#define MAXWORD 100		/* 获取的单词的最大长度 */

/* Write a cross-reference that prints a list of all words in a document,
 * and for each word, a list of the line numbers on which it occurs.
 * Remove noise words like "the", "and", and so on.
 */
int main(void)
{
	char word[MAXWORD];	/* 存放获取的单词 或者 字符 */
	struct tnode *root;
	int linenum;

	root = NULL;	/* 我写代码时,又忘了这一句,严重错误!! */
	linenum = 1;
	while (getword(word, MAXWORD) != EOF) {
		if (word[0] == '\n')
			++linenum;
		if (isalpha(word[0]) && noiseword(word) == NULL)
			root = addtree(root, word, linenum);
	}
	treeprint(root);
	return 0;
}
