#ifndef L_QSORT_H
#define L_QSORT_H

extern void qsort(void *v[], int left, int right,
		int (*comp)(const void *, const void *));

#endif	/* L_QSORT_H */
