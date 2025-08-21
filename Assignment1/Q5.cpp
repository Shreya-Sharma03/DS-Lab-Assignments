/*5) Write a program to find sum of every row and every column in a two-dimensional
array*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, c;
    cout << "Enter number of rows and columns: ";
    cin >> r >> c;
    int a[r][c];
    cout << "Enter the elements of the matrix: ";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Sum of each row: " << endl;
    for (int i = 0; i < r; i++)
    {
        int sum = 0;
        for (int j = 0; j < c; j++)
        {
            sum += a[i][j];
        }
        cout << "Sum of row " << i + 1 << " is: " << sum << endl;
    }
    cout << "Sum of each columns: " << endl;
    for (int j = 0; j < c; j++)
    {
        int sum = 0;
        for (int i = 0; i < r; i++)
        {
            sum += a[i][j];
        }
        cout << "Sum of column is " << j + 1 << " is: " << sum << endl;
    }
    return 0;
}
