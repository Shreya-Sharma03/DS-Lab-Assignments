// Transpose of a matrix:
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
    int transpose[c][r];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            transpose[j][i] = a[i][j];
        }
    }
    cout << "The transpose of the matrix is: " << endl;
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}