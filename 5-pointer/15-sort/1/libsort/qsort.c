#include "lstring.h"

static void swap(char *v[], int i, int j);

/* qsort: sort v[left] ... v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
	int i, last;
	
	if (left >= right)	/* do nothing if array contains fewer than */
		return ;		/* two elements; 这是快速排序的终止条件 */
	swap (v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; ++i)
		if (strCmp(v[i], v[left]) < 0)
			swap (v, ++last, i);
	swap (v, left, last);
	qsort (v, left, last - 1);
	qsort (v, last + 1, right);
}

static void swap(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
