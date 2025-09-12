/* Write a program to implement a stack using (b) One Queue. */
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
    int size()
    {
        return (rear - front + 1);
    }
    int peek()
    {
        if (isEmpty())
            return -1;
        return arr[front];
    }
};
class StackUsingOneQueue
{
    Queue q;

public:
    void push(int x)
    {
        int sz = q.size();
        q.enqueue(x);
        for (int i = 0; i < sz; i++)
        {
            int val = q.dequeue();
            q.enqueue(val);
        }
    }
    int pop()
    {
        if (q.isEmpty())
            return -1;
        return q.dequeue();
    }
    int top()
    {
        return q.peek();
    }
    bool isEmpty()
    {
        return q.isEmpty();
    }
};
int main()
{
    StackUsingOneQueue s;
    s.push(5);
    s.push(10);
    cout << s.pop() << endl; 
    cout << s.pop() << endl; 
    cout << s.pop() << endl; 
    return 0;
}
