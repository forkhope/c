/* Our binary search makes two tests inside the loop, when one would 
 * suffice (at the price of more tests outside.) Write a version with only
 * one test inside the loop and measure the difference in run-time.
 * 原来的程序使用 if-else if-else 的形式,最多需要测试两次(最后的else分支不
 * 需要测试);现在题目要求只测试一次,那么可以只写if,不写else;也可以写为
 * if-else 形式,这样也是只测试一次,为真就执行if,为假就执行else.
 */
int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low < high) { /* 注意,这里的条件是 low<high,而不是 low<=high */
		mid = (low + high) / 2;
		if (x <= v[mid])
			high = mid;
		else
			low = mid + 1;
	}

	return (x == v[low]) ? low : -1;
}
