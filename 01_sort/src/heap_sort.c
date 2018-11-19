/*
    MAX-HEAPIFY(A, i)
      l = LEFT(i)
      r = RIGHT(i)
      if l < A.heap-size and A[i] < A[l]
          largest = l
      else largest = i
      if r < A.heap-size and A[largest] < A[r]
          largest = r
      if larget != i
          exchange A[i] with A[largest]
	  MAX-HEAPIFY(A, largest)
 */
#define LEFT(i) (2 * (i) + 1)
#define RIGHT(i) (2 * (i) + 2)
#define exchange(p1, p2) \
		do { \
			int tmp; \
			tmp = *p1; \
			*p1 = *p2; \
			*p2 = tmp; \
		} while(0)

int max_heapify(int A[], int i, int size)
{
	int l, r, largest;

	l = LEFT(i);
	r = RIGHT(i);
	if (l < size && A[i] < A[l]) {
		largest = l;
	} else {
		largest = i;
	}
	if (r < size && A[largest] < A[r]) {
		largest = r;
	}
	if (largest != i) {
		exchange(&A[i], &A[largest]);
		max_heapify(A, largest, size);
	}
	return 0;
}
/*
    BUILD-MAX-HEAP(A)
      for i = (A.heap-size / 2 - 1) downto 0
          MAX-HEAPIFY(A, i)
 */
int build_max_heap(int A[], int size)
{
	int i;
	for (i = size / 2 - 1; i >= 0; i--) {
		max_heapify(A, i, size);
	}
	return 0;
}
/*
    HEAPSORT(A)
      BUILD-MAX-HEAP(A)
      for i = A.heap-size - 1 to 1
          exchange A[0] with A[i]
	  A.heap-size = A.heap-size - 1
	  MAX-HEAPIFY(A, 0)
 */
int heap_sort(int A[], int size)
{
	int i;

	build_max_heap(A, size);
	for (i = size - 1; i >= 0; i--) {
		exchange(&A[i], &A[0]);
		size --;
		max_heapify(A, 0, size);
	}
	return 0;
}

int sort(int n, int A[])
{
	heap_sort(A, n);
	return 0;
}
