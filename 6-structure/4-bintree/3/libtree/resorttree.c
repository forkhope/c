#include <stdio.h>
#include "libtree.h"
#include "lstring.h"

/* 增加新的树结点,该结点的值等于传进来的*root结点的值;
 * 新的树结点按单词出现次数来排序.
 */
struct tnode *addnewtree(struct tnode *p, struct tnode *root)
{
	if (p == NULL) {
		p = talloc();
		p->word = strDup(root->word);
		p->count = root->count;
		p->left = p->right = NULL;
	}
	else if (p->count > root->count)
		p->left = addnewtree(p->left, root);
	else
		p->right = addnewtree(p->right, root);
	return p;
}

/* 按照单词次数来创建一颗新的树 */
struct tnode *resorttree(struct tnode *newroot, struct tnode *oldroot)
{
	if (oldroot != NULL) {
		/* 使用旧树的根结点来为新树添加一个新的结点 */
		newroot = addnewtree(newroot, oldroot);
		/* 使用旧树的左子树结点来为新树添加一个新的结点 */
		newroot = resorttree(newroot, oldroot->left);
		/* 使用旧树的右子树结点来为新树添加一个新的结点 */
		newroot = resorttree(newroot, oldroot->right);
	}
	return newroot;
}
