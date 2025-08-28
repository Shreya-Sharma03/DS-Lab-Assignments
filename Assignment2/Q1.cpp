/* 1) Implement the binary search algorithm regarded as a fast search algorithm
with run-time complexity of Ο(log n) in comparison to the Linear Search. */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {5, 17, 25, 32, 44, 60, 77, 81, 98};
    int size = sizeof(arr) / sizeof(arr[0]);
    int low = 0, high = size - 1;
    int num;
    cout << "Enter the element to be searched: " << endl;
    cin >> num;
    int mid;
    int index = -1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == num)
        {
            cout << "Element " << num << " found at index " << mid;
            index = mid;
            break;
        }
        else if (arr[mid] < num)
            low = mid + 1;
        else if (arr[mid] > num)
            high = mid - 1;
    }
    if (index == -1)
        cout << "Element not found";

    return 0;
}