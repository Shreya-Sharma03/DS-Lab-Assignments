/* Write a program to implement a stack using (a) Two queues */
#include <iostream>
using namespace std;

#define SIZE 100

class Queue
{
public:
    int arr[SIZE];
    int front, rear;
    Queue()
    {
        front = 0;
        rear = -1;
    }
    bool isEmpty()
    {
        return front > rear;
    }
    void enqueue(int x)
    {
        if (rear < SIZE - 1)
            arr[++rear] = x;
    }
    int dequeue()
    {
        if (isEmpty())
            return -1;
        return arr[front++];
    }
    int peek()
    {
        if (isEmpty())
            return -1;
        return arr[front];
    }
    void reset()
    {
        front = 0;
        rear = -1;
    }
};
class StackUsingTwoQueues
{
    Queue q1, q2;

public:
    void push(int x)
    {
        q2.enqueue(x);

        while (!q1.isEmpty())
        {
            q2.enqueue(q1.dequeue());
        }

        Queue temp = q1;
        q1 = q2;
        q2 = temp;
        q2.reset();
    }
    int pop()
    {
        if (q1.isEmpty())
            return -1;
        return q1.dequeue();
    }
    int top()
    {
        return q1.peek();
    }
    bool isEmpty()
    {
        return q1.isEmpty();
    }
};
int main()
{
    StackUsingTwoQueues s;
    s.push(1);
    s.push(2);
    cout << s.pop() << endl; // Output: 2
    cout << s.pop() << endl; // Output: 1
    cout << s.pop() << endl; // Output: -1 (empty)
    return 0;
}
