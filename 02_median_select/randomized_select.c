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
/* RANDOMIZED-SELECT(A, p, r, i)
 *     if p == r
 *         return A[p]
 *     q = PARTITION(A, p, r)
 *     k = q - p + 1
 *     if k == i
 *         return A[q]
 *     else if i < k
 *         return RANDOMIZED-SELECT(A, p, q - 1, i)
 *     else
 *         return RANDOMIZED-SELECT(A, q + 1, r, i - k)
 * */

int randomized_select(int A[], int p, int r, int i)
{
	int q, k;

	if (p == r) {
		return A[p];
	}
	q = partition(A, p, r);
	k = q - p + 1;
	if (k == i) {
		return A[q];
	} else if (i < k) {
		return randomized_select(A, p, q - 1, i);
	} else {
		return randomized_select(A, q + 1, r, i - k);
	}
}
