#include <stdio.h>
#include <stdlib.h>

void merge_sort(int nums[], int n);
void merge(int left[], int left_size, int right[], int right_size, int nums[]);

int main()
{
	int nums[] = {3, 7, 7, 1, 2};
	int n = sizeof(nums) / sizeof(int);
	
	printf("Merge Sort\n\n");
	printf("Original Array: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", nums[i]);
	}

	printf("\n");

	merge_sort(nums, n);

	printf("Sorted Array: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", nums[i]);
	}

	printf("\n");

	return 0;
}

void merge_sort(int nums[], int n)
{
	// Base case
	if (n <= 1) return;

	int mid = n / 2;

	// Allocate memory
	int *left = (int *)malloc(mid * sizeof(int));
	int *right = (int *)malloc((n - mid) * sizeof(int));

	// Fill in the left and the right array
	for (int i = 0; i < mid; i++) {
		left[i] = nums[i];
	}
	for (int i = mid; i < n; i++) {
		right[i - mid] = nums[i];
	}

	// Recursive calls to split the array
	merge_sort(left, mid);
	merge_sort(right, n - mid);

	// Merge sorted arrays
	merge(left, mid, right, n - mid, nums);

	free(left);
	free(right);
}

void merge(int left[], int left_size, int right[], int right_size, int nums[])
{
	// Pointers corresponding to left, right and nums.
	int i = 0, j = 0, k = 0;

	// Merge left and right to nums
	while (i < left_size && j < right_size) 
	{
		if (left[i] > right[j]) {
			nums[k] = right[j];
			j++;
		} else {
			nums[k] = left[i];
			i++;
		}
		k++;
	}

	// Include left overs
	while (i < left_size) {
		nums[k] = left[i];
		i++;
		k++;
	}
	while (j < right_size) {
		nums[k] = right[j];
		j++;
		k++;
	}
}
