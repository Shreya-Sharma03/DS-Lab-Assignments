/* Develop a menu driven program demonstrating the following operations on Circular Queues:
enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().
 */
#include <iostream>
#define SIZE 5
using namespace std;

class CircularQueue
{
    int items[SIZE], front, rear;

public:
    CircularQueue()
    {
        front = -1;
        rear = -1;
    }
    bool isFull()
    {
        return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
    }
    bool isEmpty()
    {
        return front == -1;
    }
    void enqueue(int element)
    {
        if (isFull())
        {
            cout << "Queue is full!\n";
            return;
        }

        if (isEmpty())
        {
            front = rear = 0;
        }
        else if (rear == SIZE - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }

        items[rear] = element;
        cout << "Inserted " << element << endl;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!\n";
            return;
        }
        int element = items[front];
        if (front == rear)
        {
            front = rear = -1; // Queue becomes empty
        }
        else if (front == SIZE - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        cout << "Deleted " << element << endl;
    }
    void peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!\n";
        }
        else
        {
            cout << "Front element is: " << items[front] << endl;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue elements are: ";
        int i = front;
        while (true)
        {
            cout << items[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main()
{
    CircularQueue q;
    int choice, value;
    do
    {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
            break;
        case 5:
            cout << (q.isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
            break;
        case 6:
            cout << (q.isFull() ? "Queue is full.\n" : "Queue is not full.\n");
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
