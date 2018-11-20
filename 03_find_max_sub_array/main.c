#include <stdio.h>
#include <stdlib.h>

/*
	FIND-MAX-CROSSING-SUBARRAY(A, low, mid, high)
		left-sum = MIN
		sum = 0
		for i = mid downto low
			sum = sum + A[i]
			if sum > sum-left
				left-sum = sum
				max-left = i
		right-sum = MIN
		sum = 0
		for j = mid + 1 to high
			sum = sum + A[j]
			if sum > right-sum
				right-sum = sum
				max-right = j
		return(max-left, max-right, left-sum + right-sum
*/

#define MIN_NUM (1 << (sizeof(int) * 8 - 1))
int find_max_crossing_subarray(int A[], int low, int mid, int high, int *max_left, int *max_right)
{
	int left_sum, right_sum, i, sum;

	left_sum = MIN_NUM;
	sum = 0;
	*max_left = mid;
	*max_right = mid;
	for (i = mid; i >= low; i--) {
		sum += A[i];
		if (sum > left_sum) {
			left_sum = sum;
			*max_left = i;
		}
	}
	right_sum = MIN_NUM;
	sum = 0;
	for (i = mid + 1; i <= high; i++) {
		sum += A[i];
		if (sum > right_sum) {
			right_sum = sum;
			*max_right = i;
		}
	}
	return left_sum + right_sum;
}

/*
	FIND-MAXIMUN-SUBARRAY(A, low, high)
		if high == low
			return(low, high, A[low]
		else mid = (high + low) / 2
			(left-low, left-high, left-sum) =
				FIND-MAX-MAXIMUN-SUBARRAY(A, low, mid)
			(right-low, right-high, right-sum) =
				FIND-MAX-MAXIMUN-SUBARRAY(A, mid + 1, high)
			(cross-low, corss-high, corss-sum) = 
				FIND-MAX-CROSSING-SUBBARY(A, low, mid, high)
		if left-sum >= right-sum and left-sum >= cross-sum
			return(left-low, left-high, left-sum)
		else if right-sum >= left-sum and right-sum >= crocess-sum
			return(right-low, right-high, right-sum)
		else
			return(cross-low, cross-high, corss-sum)
*/
#define MAX_SUBARRY_COMPART(sum, tmp_sum, max_left, left, max_right, right) \
do { \
	if (tmp_sum > sum) { \
		sum = tmp_sum; \
		*max_left = left; \
		*max_right = right; \
	} \
} while (0)
int find_maximun_subarray(int A[], int low, int high, int *max_left, int *max_right)
{
	int mid, sum, tmp_sum, left, right;

	if (high == low) {
		*max_left = low;
		*max_right = high;
		return A[low];
	}
	else {
		mid = (high + low) / 2;
		sum = find_maximun_subarray(A, low, mid, max_left, max_right);
		tmp_sum = find_maximun_subarray(A, mid + 1, high, &left, &right);
		MAX_SUBARRY_COMPART(sum, tmp_sum, max_left, left, max_right, right);
		tmp_sum = find_max_crossing_subarray(A, low, mid, high, &left, &right);
		MAX_SUBARRY_COMPART(sum, tmp_sum, max_left, left, max_right, right);
		return sum;
	}
}

int get_number(int num, int **arr, char *argv[])
{
	int i;
	
	*arr = (int *)malloc(sizeof(int) * num);
	if (NULL == *arr) {
		printf("Error: malloc failed\n");
		return -1;
	}
	for (i = 0; i < num; i ++) {
		(*arr)[i] = atoi(argv[i + 1]);
	}
	return 0;
}

int main(int argc, char *argv[])
{
	int num, *arr, left, right, sum;

	num = argc - 1;
	if (get_number(num, &arr, argv)) {
		return -1;
	}
	sum = find_maximun_subarray(arr, 0, num - 1, &left, &right);
	printf("%d\n", sum);
	
	free(arr);
	return 0;
}
