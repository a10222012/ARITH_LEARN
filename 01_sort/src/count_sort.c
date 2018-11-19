#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/*
  COUNTING-SORT(A, B, k)
      let C[0...k] be a new array
      for i = 0 to k
          C[i] = 0
      for j = 0 to A.length - 1
          C[A[j]] = C[A[j]] + 1
      for i = 1 to k
          C[i] = C[i - 1] + C[i]
      for j = A.length - 1 downto 0
          B[C[A[j]]] = A[j]
	  C[A[j]] = C[A[j]] - 1
 */
int count_sort(int A[], int B[], int n, int k)
{
	int *C = NULL;
	int i, j;

	C = (int *)malloc(sizeof(int) * (k + 1));
	if (C == NULL) {
		printf("Error: malloc failed\n");
		return -1;
	}
	memset(C, 0, sizeof(int) * (k + 1));
	for (j = 0; j < n; j++) {
		C[A[j]] = C[A[j]] + 1;
	}
	for (i = 1; i <= k; i++) {
		C[i] = C[i - 1] + C[i];
	}
	for (j = n - 1; j >= 0; j--) {
		B[C[A[j]] - 1] = A[j];
		C[A[j]]--;
	}
	free(C);
	return 0;
}


int sort(int num, int arr[])
{
	int *res = (int *)malloc(sizeof(int) * num);
	int ret;

	if (NULL == res) {
		return -1;
	}
	ret = count_sort(arr, res, num, 100);
	if (ret == 0) {
		memcpy(arr, res, sizeof(int) * num);
	}
	free(res);
	return ret;
}
