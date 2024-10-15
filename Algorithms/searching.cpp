#include "searching.h"

int binarySearch(const std::vector<int>& arr, int key)
{
    int left = 0;
    int right = arr.size() - 1;

    while (right >= left)
    {
        int mid = (left + right) / 2;
        if (arr[mid] > key)
            right = mid - 1;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            return mid;
    }
    return -1;
}

int linear_search(const std::vector<int>& arr, int key)
{
    int index = 0;
    int length = arr.size() - 1;
    while (index < length)
    {
        if (arr[index] == key)
            return index;
    }
    return -1;
}
