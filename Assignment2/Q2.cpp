/* 2) Bubble Sort is the simplest sorting algorithm that works by repeatedly
swapping the adjacent elements if they are in the wrong order. Code the Bubble sort
with the following elements: 64 34 25 12 22 11 90  */

#include <bits/stdc++.h>
using namespace std;

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Unsorted Array: " << endl;
    display(arr, size);
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "Sorted Array: " << endl;
    display(arr, size);
    return 0;
}
