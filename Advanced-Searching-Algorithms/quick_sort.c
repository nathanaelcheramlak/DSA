#include <stdio.h>

void quick_sort(int[], int, int);
int partition(int[], int, int);

int main()
{
    int nums[] = {8, 2, 5, 3, 1, 9, -2, 0};
    int n = sizeof(nums) / sizeof(int);

    printf("Quick Sort\n");
    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    quick_sort(nums, 0, n - 1);

    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    
    return 0;
}

void quick_sort(int nums[], int start, int end) 
{
    // Base case
    if (end <= start) return;

    int pivot = partition(nums, start, end);
    quick_sort(nums, start, pivot - 1);
    quick_sort(nums, pivot + 1, end);
}

int partition(int nums[], int start, int end)
{
    int pivot = nums[end];
    int i = start - 1;

    for (int j = start; j <= end - 1; j++) {
        // Swap the nums
        if (pivot > nums[j]) {
            i++;
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }

    // Place the pivot in the correct place
    int temp = nums[++i];
    nums[i] = pivot;
    nums[end] = temp;

    return i;
}
