#include "libkey.h"

/* binsearch: find word in tab[0] ... tab[n-1], if not found, return -1 */
int binsearch(char *word, struct key tab[], int n)
{
	int low, mid, high;
	int cond;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if ((cond = strcmp(word, tab[mid].word)) < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}
