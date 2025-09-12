/* Write a program to find first non-repeating character in a string using Queue.
Sample I/P: a a b c Sample O/P: a -1 b b */
#include <iostream>
using namespace std;

#define SIZE 100

class Queue
{
public:
    char arr[SIZE];
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
    void enqueue(char c)
    {
        if (rear < SIZE - 1)
            arr[++rear] = c;
    }
    char dequeue()
    {
        return arr[front++];
    }
    char peek()
    {
        return arr[front];
    }
};
int main()
{
    int n;
    cout << "Enter number of characters: ";
    cin >> n;
    Queue q;
    int freq[256] = {0};
    cout << "Enter characters separated by spaces:\n";
    for (int i = 0; i < n; i++)
    {
        char ch;
        cin >> ch;

        freq[ch]++;
        q.enqueue(ch);

        while (!q.isEmpty() && freq[q.peek()] > 1)
        {
            q.dequeue();
        }

        if (q.isEmpty())
            cout << "-1 ";
        else
            cout << q.peek() << " ";
    }
    cout << endl;
    return 0;
}
