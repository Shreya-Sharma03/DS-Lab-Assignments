/* 2. Display all the node values in a circular linked list, repeating value of head node at the
end too.
Input: 20 → 100 → 40 → 80 → 60,
Output: 20 100 40 80 60 20. */
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};
class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList() {
        head = nullptr;
    }
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head; 
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
    void display() {
        if (head == nullptr) {
            cout << "List is empty.";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data; 
        cout << endl;
    }
};
int main() {
    CircularLinkedList list;
    list.insert(20);
    list.insert(100);
    list.insert(40);
    list.insert(80);
    list.insert(60);
    cout << "Output: ";
    list.display();
    return 0;
}