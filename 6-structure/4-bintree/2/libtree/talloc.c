#include <stdlib.h>
#include "libtree.h"

/* 申请一块刚好可以存放一个struct tnode类型变量的内存 */
struct tnode *talloc(void)
{
	return (struct tnode *)malloc(sizeof(struct tnode));
}
