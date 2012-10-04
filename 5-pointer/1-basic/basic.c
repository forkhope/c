/* 关于指针的基本概念 */
int main(void)
{
	int x = 1, y = 2, z[10] = {0};
	/* A pointer is constrained to point to a particular kind of object:
	 * every pointer points to a specific data type. (There is one
	 * exception: a "pointer to void" is used to hold any type of pointer
	 * but cannot be dereferenced itself.
	 */
	int *ip;	/* ip is a pointer to int */

	ip = &x;	/* ip now points to x, & 操作符可获取变量的地址 */
	y = *ip;	/* y is now 1, *ip 取出 ip 指向的地址里存放的值 */
	*ip = 0;	/* x is now 0, 当指针 ip 指向变量x 时, *ip 和 x 是等价的 */
	ip = &z[0];	/* ip now points to z[0] */

	return 0;
}
