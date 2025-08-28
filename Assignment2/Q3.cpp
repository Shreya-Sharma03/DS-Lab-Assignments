/* 3) Design the Logic to Find a Missing Number in a Sorted Array. Given an array of
n-1 distinct integers in the range of 1 to n, find the missing number in it in a Sorted
Array
(a) Linear time
(b) Using binary search. */

#include <bits/stdc++.h>
using namespace std;

void linear_search(int arr[], int size)
{
    int n = size + 1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != i + 1)
        {
            n = i + 1;
            break;
        }
    }
    cout << "Missing number is " << n;
    cout << endl;
}
void binary_search(int arr[], int size)
{
    int low = 0, high = size - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == mid + 1)
            low = mid + 1;
        else
            high = mid - 1;
    }
    cout << "Missing number is " << low + 1;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Using linear search:" << endl;
    linear_search(arr, size);
    cout << "Using binary search:" << endl;
    binary_search(arr, size);
    return 0;
}