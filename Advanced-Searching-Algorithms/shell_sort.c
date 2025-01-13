#include <stdio.h>
#include <stdlib.h>

void shell_sort(int[], int);
void shell_sort_skeleton(int[], int);

int main()
{
	int nums[] = {2, -1, 9, 3, 1, 8, 5, 6, 7};
	int n = sizeof(nums) / sizeof(int);

	printf("Shell Sort\n");

	printf("Original Array: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", nums[i]);
	}

	printf("\n");
	shell_sort(nums, n);
	
	printf("Sorted Array: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", nums[i]);
	}

	printf("\n");

	return 0;
}

void shell_sort(int nums[], int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i++) {
			int key = nums[i];
			int j = i;

			while (j >= gap && nums[j - gap] > key) {
				nums[j] = nums[j - gap];
				j -= gap;
			}

			nums[j] = key;
		}
	}
}

void shell_sort_skeleton(int nums[], int n) 
{
	int gap = n / 2;

	while (gap > 1) {
		int j = gap;
		while (j < n) {
			// Swap if out of order
			if (nums[j] < nums[j - gap]) {
				int temp = nums[j];
				nums[j] = nums[j - gap];
				nums[j - gap] = temp;
			}
			j++;
		}
		gap /= 2;
	}

	// Insertion sort
	for (int i = 1; i < n; i++) {
		int key = nums[i];
		int j = i - 1;

		while (j >= 0 && nums[j] > key) {
			nums[j + 1] = nums[j];
			j--;
		}
		nums[j + 1] = key;
	}	
}
