#include <stdio.h>
#include <stdlib.h>

extern int sort(int num, int arr[]);

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

int print_number(int num, int arr[])
{
	int i;
	for (i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

int main(int argc, char *argv[])
{
	int num, *arr;

	num = argc - 1;
	if (get_number(num, &arr, argv)) {
		return -1;
	}
	if (sort(num, arr)) {
		return -1;
	}
	print_number(num, arr);
	free(arr);
	return 0;
}
