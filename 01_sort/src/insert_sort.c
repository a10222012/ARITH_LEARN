/*
INSERTION-SORT(A)
	for j = 1 to A.length - 1
		key = A[j]
		//INSERT a[j] into the sorted swquence A[1 ... j - 1]
		i = j - 1
		while i >= 0 and A[i] > key
			A[i + 1] = A[i]
			i = i - 1
		A[i + 1] = key
*/

void insert_sort(int n, int A[])
{
	int i, j, key;
	for (j = 1; j < n; j++) {
		key = A[j];
		i = j - 1;
		while (i >= 0 && A[i] > key) {
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = key;
	}
	return;
}

int sort(int n, int arr[])
{
	insert_sort(n, arr);
	return 0;
}