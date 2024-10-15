#include <iostream>
#include "searching.h"
#include "sorting.h"
#include <vector>
#include <sstream>
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

void sorting_menu();
void searching_menu();
void print_array(vector<int>& arr);
void print_description(string);
void print_index(int index);
vector<int> string_to_array(string input);

int main()
{
    cout << "Welcome to Algohub" << endl;
    int response;

    do {
        cout << "1. Sorting Algorithms" << endl;
        cout << "2. Searching Algorithms" << endl;
        cout << "3. Quit" << endl;
        cout << "Response: ";
        cin >> response;

        switch (response)
        {
            case 1: sorting_menu(); break;
            case 2: searching_menu(); break;
            case 3: exit(0);

        }
    } while (response != 3);
}

void sorting_menu()
{
    cout << "Sorting Algorithms" << endl;
    int response;
    vector<int> arr;
    do {
        cout << "1. Simple Sort" << endl;
        cout << "2. Bubble Sort" << endl;
        cout << "3. Selection Sort" << endl;
        cout << "4. Insertion Sort" << endl;
        cout << "5. Go back" << endl;
        cout << "6. Quit" << endl;
        cout << "Response: ";
        cin >> response;

        if (response >= 1 && response <= 4) {
            string input;
            cout << "Enter the array separated by a comma (','): ";
            cin >> input;
            arr = string_to_array(input);
        }

        switch (response)
        {
            case 1: simple_sort(arr); print_array(arr); print_description("Simple Sort"); break;
            case 2: bubble_sort(arr); print_array(arr); print_description("Bubble Sort"); break;
            case 3: selection_sort(arr); print_array(arr); print_description("Selection Sort"); break;
            case 4: insertion_sort(arr); print_array(arr); print_description("Insertion Sort"); break;
            case 5: return;
            case 6: exit(0);
        }
    } while (response != 6);
    for (int resp : arr)
       cout << resp << endl;
}

void searching_menu()
{
    cout << "Searching Algorithms" << endl;
    vector<int> arr;
    int target;
    int response;
    int index;
    do {
        cout << "1. Linear Search" << endl;
        cout << "2. Binary Search" << endl;
        cout << "3. Go back" << endl;
        cout << "4. Quit" << endl;
        cout << "Response: ";
        cin >> response;

        if (response >= 1 && response <= 2) {
            string input;
            cout << "Enter the array separated by a comma (','): ";
            cin >> input;
            cout << "Enter Target: ";
            cin >> target;
            arr = string_to_array(input);
        }

        switch (response)
        {
            case 1:
                index = linear_search(arr, target);
                print_index(index);
                print_description("Linear Search");
                break;
            case 2:
                bubble_sort(arr);
                index = binarySearch(arr, target);
                print_index(index);
                print_description("Binary Search");
                break;
            case 3: return;
            case 4: exit(0);
        }
    } while (response != 4);

}

vector<int> string_to_array(string input)
{
    stringstream ss(input);
    string token;
    vector<int> tokens;
    char delimiter = ',';

    while (getline(ss, token, delimiter)) {
        // Remove any spaces from the token
        token.erase(remove(token.begin(), token.end(), ' '), token.end());
        tokens.push_back(stoi(token));
    }

    return tokens;
}

void print_index(int index)
{
    cout << "\n ********************************* " << endl;
    if (index != -1)
        cout << "Target found at index: " << index << endl;
    else
        cout << "Target was not found in the array." << endl;
}

void print_array(vector<int>& arr)
{
    cout << "\n ********************************* " << endl;
    string output;
    output += "Sorted: [";

    for (size_t i = 0; i < arr.size(); ++i) {
        output += to_string(arr[i]);  // Convert int to string
        if (i != arr.size() - 1)      // Add a comma and space except for the last element
            output += ", ";
    }

    output += "]";  // Close the bracket
    cout << output << endl;
}

void print_description(string algorithm_name)
{
    unordered_map<string, string> name_to_time_complexity;
    name_to_time_complexity["Simple Sort"] = "O(N ^ 2)";
    name_to_time_complexity["Bubble Sort"] = "O(N ^ 2)";
    name_to_time_complexity["Insertion Sort"] = "O(N ^ 2)";
    name_to_time_complexity["Selection Sort"] = "O(N ^ 2)";
    name_to_time_complexity["Linear Search"] = "O(N)";
    name_to_time_complexity["Binary Search"] = "O(log N)";

    unordered_map<string, string> name_to_space_complexity;
    name_to_space_complexity["Simple Sort"] = "O(1)";
    name_to_space_complexity["Bubble Sort"] = "O(1)";
    name_to_space_complexity["Insertion Sort"] = "O(1)";
    name_to_space_complexity["Selection Sort"] = "O(1)";
    name_to_space_complexity["Linear Search"] = "O(1)";
    name_to_space_complexity["Binary Search"] = "O(1)";

    unordered_map<string, string> descriptions;
    descriptions["Simple Sort"] = "Simple Sort iteratively compares each element with all subsequent elements, swapping them to order the smallest elements first. This process continues until the entire vector is sorted in ascending order.";
    descriptions["Bubble Sort"] = "The bubble sort algorithm repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. This process continues until no more swaps are needed, gradually bubbling larger elements to the end of the list.";
    descriptions["Insertion Sort"] = "The insertion sort algorithm builds a sorted portion of the list by repeatedly taking the next unsorted element and inserting it into the correct position within the sorted portion. This is done by shifting larger elements to the right to make space for the new element.";
    descriptions["Selection Sort"] = "The selection sort algorithm repeatedly finds the smallest element from the unsorted portion and swaps it with the first unsorted element. This process continues until the entire list is sorted.";
    descriptions["Linear Search"] = "Linear search checks each element in the list sequentially until it finds the target value or reaches the end of the list.";
    descriptions["Binary Search"] = "Binary search efficiently finds a target value in a sorted list by repeatedly dividing the search interval in half, eliminating half of the remaining elements each time. \n Caution: The array has been sorted for safety purposes.";

    cout << "Time Complexity: " << name_to_time_complexity[algorithm_name] << endl;
    cout << "Space Complexity: " << name_to_space_complexity[algorithm_name] << endl << endl;
    cout << "Description:" << endl << descriptions[algorithm_name] << endl;


    cout << " ********************************* \n" << endl;
}

