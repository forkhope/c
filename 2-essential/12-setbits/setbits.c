/* Write a function setbits(x, p, n, y) that returns x with the n bits that
 * begin at position p set to the rightmost n bits of y, leaving the other
 * bits unchanged.
 */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	unsigned temp;

	/* 注意下面 ~0 的使用,详细说明见 getbits/ 下的 getbits.c 文件 */
	temp = ((x >> (p+1-n)) | ~(~0 << n)) & y;
	return (temp << (p+1-n));
}
