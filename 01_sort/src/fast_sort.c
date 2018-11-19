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

#define exchange(p1, p2) \
	do { \
		int tmp; \
		tmp = *p2; \
		*p2 = *p1; \
		*p1 = tmp; \
	} while(0)

int partition(int A[], int p, int r)
{
	int x, i, j;

	x = A[r];
	i = p - 1;
	for (j = p; j < r; j++) {
		if (A[j] <= x) {
			i++;
			exchange(&A[i], &A[j]);
		}
	}
	exchange(&A[i + 1], &A[r]);
	return i + 1;
}

/*
     QUICKSORT(A, p, r)
       if p < r
           q = PARTITION(A, p, r)
	   QUICKSORT(A, p, q - 1)
	   QUICKSORT(A, q + 1, r)
 */
int quick_sort(int A[], int p, int r)
{
	int q;

	if (p < r) {
		q = partition(A, p, r);
		quick_sort(A, p, q - 1);
		quick_sort(A, q + 1, r);
	}
	return 0;
}

int sort(int n, int arr[])
{
	quick_sort(arr, 0, n - 1);
	return 0;
}
