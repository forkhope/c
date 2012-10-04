/* bitcount: count 1 bits in x.
 * Declaring the argument x to be an unsigned ensures that when it is 
 * right-shifted, vacated bits whil be filled with zeros, not sign bits,
 * regardless of the machine the program is run on.
 */
int bitcount(unsigned x)
{
	int b;

	/* 下面循环的终止条件是 x != 0,而不是 i < 32 或者 i < sizeof(unsigned)
	 * 之类;写成 x != 0 的好处是尽可能的减少循环次数,不像写成后两种那样,循环
	 * 次数是固定的;因为事实上,除非 x 的最高一位是 1, 否则最多只需要循环 31
	 * 次(在32位机器上),以此类推,当 x 越小,循环次数就越少; 若 x 等于 0,甚至
	 * 都不执行循环,直接就返回了 0,但是如果循环的终止条件是后两种的话,它还是
	 * 会"傻傻的"执行32次循环.这是没有必要的,程序的效率就很低.
	 * 由此可见,在写循环时,选择一个恰当而巧妙的循环条件非常重要,值得注意.
	 * 另外,说明一点, x *= y + 1 相当于 x = x * (y + 1),在使用赋值操作符时,
	 * 右边的表达式默认被括号括起来,因为赋值操作符的优先级很低,仅高于逗号.
	 */
	for (b = 0; x != 0; x >>= 1)
		if (x & 01)
			++b;
	return b;
}
