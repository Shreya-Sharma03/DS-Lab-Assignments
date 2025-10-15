/* 3. Write a program to find size of
i. Doubly Linked List. */
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int value)
    {
        data = value;
        next = prev = NULL;
    }
};
Node *addNode(Node *head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
        return newNode;
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}
int size(Node *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}
int main()
{
    Node *head = NULL;
    head = addNode(head, 10);
    head = addNode(head, 20);
    head = addNode(head, 30);
    head = addNode(head, 40);
    cout << "Size of doubly linked list is: " << size(head) << endl;
    return 0;
}