/*Matrix Multiplication*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r1, r2, c1, c2;
    int a[25][25], b[25][25];
    cout << "Enter rows and columns of 1st matrix: " << endl;
    cin >> r1 >> c1;
    cout << "Enter rows and columns of 2nd matrix: " << endl;
    cin >> r2 >> c2;
    if (c1 != r2)
    {
        cout << "Matrix multiplication is not possible";
        return 0;
    }
    cout << "Enter the elements of 1st matrix: ";
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Enter the elements of 2nd matrix: ";
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cin >> b[i][j];
        }
    }
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    int c[25][25];
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < c1; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    cout << "Multiplication Matrix: " << endl;
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
