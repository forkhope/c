/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1].
 * The function returns the position (a number between 0 and n-1) if x
 * occurs in v, and -1 if not.
 */
int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else		/* found match */
			return mid;
	}
	return -1;	/* no match */
}
