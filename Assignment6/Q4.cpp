// 4. Write a program to check if a doubly linked list of characters is palindrome or not.
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    char data;
    Node *prev;
    Node *next;
    Node(char value)
    {
        data = value;
        prev = next = NULL;
    }
};
bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
        return true;
    Node *left = head;
    Node *right = head;
    while (right->next != NULL)
    {
        right = right->next;
    }
    while (left != right && left->prev != right)
    {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    string input;
    cout << "Enter a word: ";
    cin >> input;
    for (char ch : input)
    {
        Node *newNode = new Node(ch);
        if (head == NULL)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    if (isPalindrome(head))
        cout << "True\n";
    else
        cout << "False\n";
    return 0;
}