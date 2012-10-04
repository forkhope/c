#ifndef L_QSORT_H
#define L_QSORT_H

extern void qsort(void *v[], int left, int right,
		int (*comp)(const void *, const void *));
extern void rorder(void *v[], int n);

#endif	/* L_QSORT_H */
