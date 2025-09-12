/* 6) Write a program to implement the following operations on a Sparse Matrix,
assuming the matrix is represented using a triplet.
(a) Transpose of a matrix.
(b) Addition of two matrices.
(c) Multiplication of two matrices. */

#include <iostream>
using namespace std;

void transpose(int mat[20][3], int res[20][3])
{
    res[0][0] = mat[0][1];
    res[0][1] = mat[0][0];
    res[0][2] = mat[0][2];
    int k = 1;
    for (int col = 0; col < mat[0][1]; col++)
    {
        for (int i = 1; i <= mat[0][2]; i++)
        {
            if (mat[i][1] == col)
            {
                res[k][0] = mat[i][1];
                res[k][1] = mat[i][0];
                res[k++][2] = mat[i][2];
            }
        }
    }
}

void add(int a[20][3], int b[20][3], int res[20][3])
{
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1])
    {
        res[0][2] = -1;
        return;
    }
    res[0][0] = a[0][0];
    res[0][1] = a[0][1];
    int i = 1, j = 1, k = 1;
    while (i <= a[0][2] && j <= b[0][2])
    {
        if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1]))
            res[k][0] = a[i][0], res[k][1] = a[i][1], res[k++][2] = a[i++][2];
        else if (b[j][0] < a[i][0] || (a[i][0] == b[j][0] && b[j][1] < a[i][1]))
            res[k][0] = b[j][0], res[k][1] = b[j][1], res[k++][2] = b[j++][2];
        else
        {
            res[k][0] = a[i][0];
            res[k][1] = a[i][1];
            res[k++][2] = a[i++][2] + b[j++][2];
        }
    }
    while (i <= a[0][2])
        res[k][0] = a[i][0], res[k][1] = a[i][1], res[k++][2] = a[i++][2];
    while (j <= b[0][2])
        res[k][0] = b[j][0], res[k][1] = b[j][1], res[k++][2] = b[j++][2];
    res[0][2] = k - 1;
}

void multiply(int a[20][3], int b[20][3], int res[20][3])
{
    int bt[20][3], k = 1;
    transpose(b, bt);
    res[0][0] = a[0][0];
    res[0][1] = b[0][1];
    for (int i = 0; i < a[0][0]; i++)
    {
        for (int j = 0; j < b[0][1]; j++)
        {
            int sum = 0;
            for (int p = 1; p <= a[0][2]; p++)
            {
                if (a[p][0] == i)
                {
                    for (int q = 1; q <= bt[0][2]; q++)
                    {
                        if (bt[q][0] == j && bt[q][1] == a[p][1])
                            sum += a[p][2] * bt[q][2];
                    }
                }
            }
            if (sum)
                res[k][0] = i, res[k][1] = j, res[k++][2] = sum;
        }
    }
    res[0][2] = k - 1;
}

void print(int mat[20][3])
{
    for (int i = 0; i <= mat[0][2]; i++)
        cout << mat[i][0] << " " << mat[i][1] << " " << mat[i][2] << endl;
}

int main()
{
    int A[20][3] = {{3, 3, 3}, {0, 0, 5}, {1, 1, 8}, {2, 2, 3}};
    int B[20][3] = {{3, 3, 3}, {0, 0, 1}, {1, 1, 2}, {2, 2, 3}};
    int T[20][3], SUM[20][3], PROD[20][3];

    cout << "Matrix A:\n";
    print(A);
    cout << "Matrix B:\n";
    print(B);

    transpose(A, T);
    cout << "\nTranspose of A:\n";
    print(T);
    add(A, B, SUM);
    cout << "\nA + B:\n";
    if (SUM[0][2] == -1)
        cout << "Invalid dimensions for addition.\n";
    else
        print(SUM);

    multiply(A, B, PROD);
    cout << "\nA * B:\n";
    print(PROD);
    return 0;
}

