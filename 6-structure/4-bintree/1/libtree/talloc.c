#include <stdlib.h>		/* 声明 malloc() 函数 */
#include "libtree.h"

struct tnode *talloc(void)
{
	return (struct tnode *)malloc(sizeof(struct tnode));
}
