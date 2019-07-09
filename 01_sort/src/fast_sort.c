#include <string.h>
#include <stdlib.h>

#define exchange(p1, p2) \
	do { \
		int tmp; \
		tmp = *p2; \
		*p2 = *p1; \
		*p1 = tmp; \
	} while(0)

#ifdef PARTITION_FUNC1
/*
     PARTITION(A, p, r)
       x = A[r]
       i = p - 1
       for j = p to r - 1
           if A[j] <= x
	       i = i + 1
	       exchange A[i] with A[j]
       exchange A[i + 1] with A[r]
       return i + 1
 */

int partition(int A[], int p, int r)
{
	int x, i, j;

	x = A[r - 1];
	i = p - 1;
	for (j = p; j < r - 1; j++) {
		if (A[j] <= x) {
			i++;
			exchange(&A[i], &A[j]);
		}
	}
	exchange(&A[i + 1], &A[r - 1]);
	return i + 1;
}
#endif

#ifdef PARTITION_FUNC2
int partition(int A[], int p, int r)
{
	int x, i, j;

	x = A[p];
	i = p;
	j = r;
	while(1) {
		do {
			j--;
		} while (A[j] > x && i < j);
		do {
			i++;
		} while (A[i] <= x && i < j);
		if (i < j) {
			exchange(&A[i], &A[j]);
		} else {
			exchange(&A[p], &A[j]);
			return j;
		}
	}
}

#endif

#ifdef PARTITION_FUNC3
int partition(int A[], int p, int r)
{
	int x, i, j, a1, a2, b1, b2, len;

	len = r - p;
	i = p;
	j = r;
	a1 = p;
	a2 = r - 1;
	b1 = -1;
	b2 = len;

	int *B = (int *)malloc(len * sizeof(int));
	memset(B, 0, len * sizeof(int));
	B[++b1] = A[i];
	x = A[i];

	while (1) {
		while (A[--j] > x && i < j) {
			A[a2--] = A[j];
		}
		while (A[++i] <= x && i <= j) {
			A[a1++] = A[i];
		}
		if (i < j) {
			B[++b1] = A[i];
			B[--b2] = A[j];
		} else {
			break;
		}
	}
	if (b2 < len) {
		memcpy(&A[a1], &B[b2], sizeof(int)* (len - b2));
		a1 += len - b2;
	}
	memcpy(&A[a1], &B[0], sizeof(int)* (b1 + 1));

	return a1;
}

#endif
/*
     QUICKSORT(A, p, r)
       if p < r
           q = PARTITION(A, p, r)
	   QUICKSORT(A, p, q)
	   QUICKSORT(A, q + 1, r)
 */
int quick_sort(int A[], int p, int r)
{
	int q;

	if (p < r) {
		q = partition(A, p, r);
		quick_sort(A, p, q);
		quick_sort(A, q + 1, r);
	}
	return 0;
}

int sort(int n, int arr[])
{
	quick_sort(arr, 0, n);
	return 0;
}

