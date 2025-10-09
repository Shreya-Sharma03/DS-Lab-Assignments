/* 3. Write a program to find size of
ii. Circular Linked List.
 */
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int v) { data = v; next = NULL; }
};
class CircularList {
    Node* head;
public:
    CircularList() { head = NULL; }
    void insert(int v) {
        Node* n = new Node(v);
        if (!head) { head = n; n->next = head; return; }
        Node* t = head;
        while (t->next != head) t = t->next;
        t->next = n;
        n->next = head;
    }
    int size() {
        if (!head) return 0;
        int c = 0;
        Node* t = head;
        do { c++; t = t->next; } while (t != head);
        return c;
    }
};
int main() {
    CircularList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    cout << "Size = " << list.size();
    return 0;
}