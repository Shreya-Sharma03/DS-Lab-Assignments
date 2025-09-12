/* Develop a menu driven program demonstrating the following operations on simple
Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek(). */
#include <iostream>
using namespace std;

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;
int isEmpty()
{
    if (front == -1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if (rear == MAX - 1)
        return 1;
    else
        return 0;
}
void enqueue(int val)
{
    if (isFull() == 1)
    {
        cout << "Queue is full\n";
        return;
    }
    if (isEmpty() == 1)
    {
        front = 0;
    }
    rear = rear + 1;
    queue[rear] = val;
    cout << val << " added\n";
}
void dequeue()
{
    if (isEmpty() == 1)
    {
        cout << "Queue is empty\n";
        return;
    }
    cout << queue[front] << " removed\n";
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = front + 1;
    }
}
void display()
{
    if (isEmpty() == 1)
    {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Queue: ";
    for (int i = front; i <= rear; i++)
    {
        cout << queue[i] << " ";
    }
    cout << "\n";
}
void peek()
{
    if (isEmpty() == 1)
    {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Front element: " << queue[front] << "\n";
}
int main()
{
    int choice, val;
    do
    {
        cout << "\n1.Enqueue 2.Dequeue 3.isEmpty 4.isFull 5.Display 6.Peek 7.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter value: ";
            cin >> val;
            enqueue(val);
        }
        else if (choice == 2)
        {
            dequeue();
        }
        else if (choice == 3)
        {
            if (isEmpty() == 1)
                cout << "Queue is empty\n";
            else
                cout << "Queue is not empty\n";
        }
        else if (choice == 4)
        {
            if (isFull() == 1)
                cout << "Queue is full\n";
            else
                cout << "Queue is not full\n";
        }
        else if (choice == 5)
        {
            display();
        }
        else if (choice == 6)
        {
            peek();
        }
        else if (choice == 7)
        {
            cout << "Exiting program\n";
        }
        else
        {
            cout << "Invalid choice\n";
        }

    } while (choice != 7);
    return 0;
}
