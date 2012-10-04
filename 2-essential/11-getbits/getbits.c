/* The function getbits(x, p, n) that returns the (right-adjusted) n-bit
 * field of x that begins at position p. We assume that bit position 0 is 
 * at the right end and that n and p are sensible positive values.
 */
unsigned getbits(unsigned x, int p, int n)
{
	/* The shift operators << and >> perform left and right shifts of their
	 * left operand by the number of bit positions given by the right 
	 * operand, which must be non-negative. 左操作数可以是负数,右操作数不行.
	 * 注意下面~0的使用,书中有这样的解释: Note that x & ~077 is independent
	 * of word length, and is thus preferable to, for example, x & 0177700,
	 * which assumes that x is a 16-bit quantity. The portable form involves
	 * no extra cost, since ~077 is a constant expression that can be 
	 * evaluated at compile time. 这里强调是的 ~077 这样的写法于不依赖字长.
	 */
	return (x >> (p+1-n)) & ~(~0 << n);
}
