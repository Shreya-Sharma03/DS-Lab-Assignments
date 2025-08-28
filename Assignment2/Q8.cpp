/* 8) Write a program to count the total number of distinct elements in an array of
length n. */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of elements: " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        bool isDistinct = true;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                isDistinct = false;
                break;
            }
        }
        if (isDistinct)
        {
            count++;
        }
    }
    cout << "Total number of distinct elements: " << count << endl;
    return 0;
}