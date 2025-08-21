/*2) Design the logic to remove the duplicate elements from an Array and after the
deletion the array should contain the unique elements.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[50], size;
    cout << "Enter the size of array: " << endl;
    cin >> size;
    cout << "Enter the elements of array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    int b[50];
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        int flag = 0;
        for (int j = 0; j < count; j++)
        {
            if (a[i] == b[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            b[count] = a[i];
            count++;
        }
    }
    cout << "Array after removing duplicate elements is: " << endl;
    for (int i = 0; i < count; i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}
