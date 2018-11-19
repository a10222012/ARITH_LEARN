#include <stdio.h>
#include <stdlib.h>
/*
	MERGE(A, p, q, r)
	n1 = q - p + 1
	n2 = r - q
	let L[0, 1, 2, ... n1] and R[0, 1, 2, ... n2]
	for i = 0 to n1 - 1
		L[i] = A[p + i]
	for i = 0 to n2 - 1
		R[i] = A[q + i + 1]
	L[n1] = MAX
	R[n2] = MAX
	i = 0
	j = 0
	for k = p to r
		if L[i] <= R[j]
			A[k] = L[i]
			i = i + 1
		else
			A[k] = R[j]
			j = j + 1
 */
#define BIG ((1 << (sizeof(int) * 8 - 1)) - 1)
int merge(int A[], int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int *L = (int *)malloc(sizeof(int) * (n1 + 1));
	if (L == NULL) {
		printf("err malloc\n");
		return -1;
	}
	int *R = (int *)malloc(sizeof(int) * (n2 + 1));
	if (R == NULL) {
		printf("err malloc\n");
		free(L);
		return -1;
	}
	int i, j, k;
	for (i = 0; i < n1; i++) {
		L[i] = A[p + i];
	}
	for (i = 0; i < n2; i++) {
		R[i] = A[q + i + 1];
	}
	L[n1] = BIG;
	R[n2] = BIG;
	i = 0;
	j = 0;
	for (k = p; k <= r; k++) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		} else {
			A[k] = R[j];
			j++;
		}
	}
	free(R);
	free(L);
	return 0;
}

/*
 	MERGE-SORT(A, p, r)
	if p < r
		q = (p + r)/2
		MERGE-SORT(A, p, q)
		MERGE-SORT(A, q + 1, r)
		MERGE(A, p, q, r)
 */
int merge_sort(int A[], int p, int r)
{
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(A, p, q);
		merge_sort(A, q + 1, r);
		return merge(A, p, q, r);
	}
	return 0;
}

int sort(int n, int arr[])
{
	return merge_sort(arr, 0, n - 1);
}

