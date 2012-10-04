static void swap(void *v[], int i, int j);

/* qsort: sort v[left] .. v[right] into increasing order.
 * The fourth parameter of qsort is 
 * 		int (*comp) (const void *, const void *)
 * which says that comp is a pointer to a function that has two 
 * const void * arguments and returns an int.
 */
void qsort(void *v[], int left, int right,
		int (*comp)(const void *, const void *))
{
	int i, last;

	if (left >= right)
		return ;
	swap (v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; ++i)
		if ((*comp)(v[i], v[left]) < 0)
				swap (v, ++last, i);
	swap (v, left, last);
	qsort (v, left, last - 1, comp);
	qsort (v, last + 1, right, comp);
}

/* reverse pointers order */
void rorder(void *v[], int n)
{
	int i;

	for (i = 0, --n; i < n; ++i, --n)
		swap (v, i, n);
}

/* swap: interchange v[i] and v[j] */
void swap(void *v[], int i, int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
