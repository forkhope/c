#include <stdio.h>

extern char *alloc(const int n);
extern void afree(char *p);

/* 测试 alloc() 和 afree() 函数 */
int main(void)
{
	char *p;
	int n, i;

	n = 10;
	p = alloc(n);
	for (i = 0; i < n; ++i)
		*(p+i) = 'a' + i;
	for (i = 0; i < n; ++i)
		printf("%c ", *(p+i));
	printf("\n");
	/* 下面的afree(p)尽管说是释放了p指向的空间,但这其实只是说,alloc(n)函数
	 * 可以把p指向的空间分配出去,该空间中存有的数据在没有被覆盖之前依然存在
	 * 且通过 p指针 还可以引用到这些数据,因为 p指针始终指向那块空间. 如下:
	 */
	afree(p);
	for (i = 0; i < n; ++i)		// 由于程序中覆盖之前分配的空间,里面的数据
		printf("%c ", *(p+i));	// 依然存在,这个for打印的结果和上面一样.
	printf("\n");		
	return 0;
}
