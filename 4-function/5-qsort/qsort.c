/* 快速排序的实现
 * qsort: sort v[left] ... v[right] into increasing order 
 */
void qsort(int v[], int left, int right)
{
	int i, last;
	void swap(int v[], int i, int j);

	/* do nothing if array contains fewer than two elements */
	if (left >= right) 
		return ;	/* 当数组区间中只有一个元素时,不再进行排序 */
	swap(v, left, (left + right) / 2);	/* 选取中间的元素作为排序的标准 */
	last = left;
	for (i = left + 1; i <= right; ++i)	/* partition, 隔开, 分开 */
		if (v[i] < v[left])
			swap(v, ++last, i);
	swap(v, left, last);		/* restore partition elem */
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}

/* interchange v[i] and v[j] */
void swap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
