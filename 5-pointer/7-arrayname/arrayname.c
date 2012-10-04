#include <stdio.h>

/* 探讨指针运算中的几个问题,以及数组首地址的地址加 1 的意义 */
int main(void)
{
	int a[5] = {1, 2, 3, 4, 5};
	int *p;
	int paddr, qaddr;

	/* The array name is the address of the zeroth element.
     * 即,数组名是一个常量指针,该指针的值等于数组首元素的地址,&array[0].
     * 所以下面的 p = a 和 p = &a[0] 是等价的.
	 */
	p = a;
	printf("*p = %d\n", *p);	/* *p == a[0],将打印出 1 */
	p = &a[0];
	printf("*(p+2) = %d\n", *(p+2));	/* 将打印出 3 */

	/* The construction "p + n" means the address of the n-th object beyond
	 * the one p currently points to. This is true regardless of the kind
	 * of object p points to; n is scaled according to the size of the 
	 * objects p points to, which is determined by the declaration of p.
	 * 即 p + n 指向的地址 和 p当前指向的地址 之间相差sizeof(*p) * n 个字节
	 * 注意这里是 sizeof(*p)*n,而不是sizeof(p)*n,因为上面说的是 size of the
	 * objects p points to,指的是p所指向的对象,而不是p本身.注意这种区别.
	 */
	paddr = (int)p;	/* 进行类型转换,表示取的是指针本身的值,即该地址的值 */
	qaddr = (int)(p + 4);	/* 这里不能写为(int)p + 4,否则结果和预期不符 */
	printf("指针p 的值是: %d\n", paddr);
	printf("指针p + 4 后的值是: %d\n", qaddr);
	printf("指针p + 4 和 指针p 之间相差的字节数是: %d\n", qaddr - paddr);
	printf("可见 p + 4 指向的地址 和 p当前指向的地址 之间相差:"
			"sizeof(*p) * 4 = %d * 4 个字节\n", sizeof(*p));

	printf("------------------------------------------------\n");
	printf("数组 a 占用的字节数是: %d\n", sizeof(a));
	printf("数组 a 的首地址的值是: %d\n", (int)a);
	printf("数组 a 的首地址加 1 后的值是: %d\n", (int)(a + 1));
	p = (int*)(&a + 1);		/* &a == 数组的首地址的首地址 */
	printf("数组 a 的首地址的地址加 1 后的值是: %d\n", (int)p);
	/* 下面使用sizeof(a)的原因是,数组的首地址的地址是 &a,则根据上面的注释,
	 * 可知, &a + 1 = sizeof(*(&a)) * 1 = sizeof(a) * 1.
	 */
	printf("可见,&a + 1 =  %d = a + sizeof(a) * 1 = %d + %d * 1\n",
			(int)p, (int)a, sizeof(a));
	return 0;
}
