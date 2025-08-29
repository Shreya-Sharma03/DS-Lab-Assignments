#include <iostream>
using namespace std;
int main()
{
    int stack[5], top = -1, choice, value;
    do
    {
        cout << "\n1.Push\n2.Pop\n3.isEmpty\n4.isFull\n5.Display\n6.Peek\n7.Exit\n";
        cout << "Enter choice: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (top == 4)
                cout << "Stack is full\n";
            else
            {
                cout << "Enter value: ";
                cin >> value;
                stack[++top] = value;
                cout << value << " pushed\n";
            }
            break;
        case 2:
            if (top == -1)
                cout << "Stack is empty\n";
            else
                cout << stack[top--] << " popped\n";
            break;
        case 3:
            if (top == -1)
                cout << "Stack is empty\n";
            else
                cout << "Stack is not empty\n";
            break;
        case 4:
            if (top == 4)
                cout << "Stack is full\n";
            else
                cout << "Stack is not full\n";
            break;
        case 5:
            if (top == -1)
                cout << "Stack is empty\n";
            else
            {
                cout << "Stack elements: ";
                for (int i = top; i >= 0; i--)
                {
                    cout << stack[i] << endl;
                }
            }
            break;
        case 6:
            if (top == -1)
                cout << "Stack is empty\n";
            else
                cout << "Top element: " << stack[top] << endl;
            break;
        case 7:
            cout << "Exit\n";
            break;
        default:
            cout << "Invalid Choice\n";
        }
    } while (choice != 7);
    return 0;
}