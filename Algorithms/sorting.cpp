#include "sorting.h"

void simple_sort(std::vector<int>& arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
        for (int j = i + 1; j < arr.size(); j++)
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

void bubble_sort(std::vector<int>& arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selection_sort(std::vector<int>& arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
        // swap(arr[i], arr[min_index]);
    }
}

void insertion_sort(std::vector<int>& arr)
{
    for (int i = 1; i < arr.size(); ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
