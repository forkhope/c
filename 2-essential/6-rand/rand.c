/* A portable implementation of a pseudo-radom number generator and a
 * function for initializing the seed.
 */
#undef RAND_MAX
#define RAND_MAX	2147483647

unsigned long int next = 1;

/* rand: return pseudo-random integer on 0..RAND_MAX.
 * 通常, RAND_MAX 的值等于 INT_MAX 的值, 32位机器上该值是 2147483647
 */
int rand(void)
{
	next = (next * 1103515245 + 12345) & RAND_MAX;
	return (unsigned int)(next);
}

/* srand: set seed for rand() */
void srand(unsigned int seed)
{
	next = seed;
}
