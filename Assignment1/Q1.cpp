/*1) Develop a Menu driven program to demonstrate the following operations of Arrays
——MENU——-
1.CREATE
2.DISPLAY
3.INSERT
4.DELETE
5.LINEAR SEARCH
6.EXIT
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[50], n, size;
    while (1)
    {
        cout << "---MENU---" << endl;
        cout << "1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n"
             << endl;
        cout << "Enter your choice: ";
        cin >> n;
        switch (n)
        {
        case 1:
        {
            cout << "Enter the size of array: ";
            cin >> size;
            cout << "Enter the elements of array: ";
            for (int i = 0; i < size; i++)
            {
                cin >> a[i];
            }
            break;
        }
        case 2:
        {
            cout << "Array is " << endl;
            for (int i = 0; i < size; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
            break;
        }
        case 3:
        {
            int element, idx;
            cout << "Enter the element to be inserted: ";
            cin >> element;
            cout << "Enter the index where element is to be inserted: ";
            cin >> idx;
            for (int i = size; i > idx; i--)
            {
                a[i] = a[i - 1];
            }
            a[idx] = element;
            size++;
            break;
        }
        case 4:
        {
            int position;
            cout << "Enter the position to be deleted: ";
            cin >> position;
            for (int i = position; i < size - 1; i++)
            {
                a[i] = a[i + 1];
            }
            size--;
            break;
        }
        case 5:
        {
            int element, found = 0;
            cout << "Enter element to search: ";
            cin >> element;
            for (int i = 0; i < size; i++)
            {
                if (a[i] == element)
                {
                    cout << "Element found at index " << i << endl;
                    found = 1;
                    break;
                }
            }
            if (!found)
                cout << "Element not found at any index" << endl;
            break;
        }
        case 6:
        {
            exit(0);
        }
        default:
        {
            cout << "Invalid Choice" << endl;
        }
        }
    }
    return 0;
}
