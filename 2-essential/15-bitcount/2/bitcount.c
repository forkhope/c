/* In a two's complement number system, x &= (x -1) deletes the rightmost
 * 1-bit in x. Explain why. Use this observation to write a faster version
 * of bitcount(). 这里的"faster version"体现在程序中,主要就是循环次数更少.
 */
int bitcount(unsigned x)
{
	int b;

	/* x &= (x - 1) 使得循环次数达到最少,有多少个 1,就循环多少次;而 x >>= 1
	 * 的循环次数取决于最左边的 1-bit 作为的位置;例如 00010111,使用前一种方
	 * 法,需要循环 4次,而使用后一种方法时,需要循环 5次,比不上前一种方法高效
	 */
	for (b = 0; x != 0; x &= (x - 1))
		++b;
	return b;
}
