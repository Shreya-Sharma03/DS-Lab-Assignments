/* 5) Space required to store any two-dimensional array is number oƒ rows × number oƒ
columns. Assuming an array is used to store elements of the following matrices,
implement an efficient way that reduces the space requirement. */

// (a) Diagonal Matrix.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size of matrix (n): " << endl;
    cin >> n;
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int diag[n];
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i][i] != 0)
        {
            diag[k] = arr[i][i];
            k++;
        }
    }
    cout << "Array of non-zero diagonal elements: " << endl;
    for (int i = 0; i < k; i++)
    {
        cout << diag[i] << " ";
    }
    return 0;
}

// (b) Tri-diagonal Matrix.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size of matrix (n): " << endl;
    cin >> n;
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int tri_diag[3 * n - 2];
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j || i == j - 1 || i == j + 1)
            {
                if (arr[i][j] != 0)
                {
                    tri_diag[k] = arr[i][j];
                    k++;
                }
            }
        }
    }
    cout << "Array of non-zero tri-diagonal elements is: " << endl;
    for (int i = 0; i < k; i++)
    {
        cout << tri_diag[i] << " ";
    }
    return 0;
}

//(c) Lower triangular Matrix.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size of matrix (n): " << endl;
    cin >> n;
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int lower[n * (n + 1) / 2];
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (arr[i][j] != 0)
            {
                lower[k] = arr[i][j];
                k++;
            }
        }
    }
    cout << "Non-zero lower-triangular array: " << endl;
    for (int i = 0; i < k; i++)
    {
        cout << lower[i] << " ";
    }
    return 0;
}

// (d) Upper triangular Matrix.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size of matrix (n): " << endl;
    cin >> n;
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int upper[n * (n + 1) / 2];
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                upper[k] = arr[i][j];
                k++;
            }
        }
    }
    cout << "Non-zero upper-triangular array: " << endl;
    for (int i = 0; i < k; i++)
    {
        cout << upper[i] << " ";
    }
    return 0;
}

// (e) Symmetric Matrix
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size of matrix (n): " << endl;
    cin >> n;
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int sym[n * (n + 1) / 2];
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (arr[i][j] != 0)
            {
                sym[k] = arr[i][j];
                k++;
            }
        }
    }
    cout << "Non-zero symmetric matrix array: " << endl;
    for (int i = 0; i < k; i++)
    {
        cout << sym[i] << " ";
    }
    return 0;
}
