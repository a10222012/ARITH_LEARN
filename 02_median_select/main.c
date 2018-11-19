#include <stdio.h>
#include <stdlib.h>

extern int randomized_select(int A[], int p, int r, int i);

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
	int num, len, *arr;
	int res;

	num = argc - 1;
	len = num - 1;
	if (get_number(num, &arr, argv)) {
		return -1;
	}
	res = randomized_select(&arr[1], 0, len - 1, arr[0]);
	printf("%d\n", res);
	free(arr);
	return 0;
}
