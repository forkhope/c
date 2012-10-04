#include <stdlib.h>		/* 声明 malloc() 函数 */
#include "libtree.h"

Treeptr talloc(void)
{
	return (Treeptr)malloc(sizeof(Treenode));
}
