/*Given a linked list, determine whether it contains a loop (cycle) using a hash set.
A loop exists if some node’s next pointer points to a previous node in the list.*/
#include <iostream>
#include <unordered_set>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};
class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void append(int x) {
        if (!head) {
            head = new Node(x);
        } else {
            Node* p = head;
            while (p->next) p = p->next;
            p->next = new Node(x);
        }
    }
    bool hasCycle() {
        unordered_set<Node*> seen;
        Node* p = head;
        while (p != nullptr) {
            if (seen.find(p) != seen.end()) {
                return true;
            }
            seen.insert(p);
            p = p->next;
        }
        return false;
    }
};
int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    Node* p = list.head;
    Node* second = nullptr;
    int count = 1;
    while (p->next) {
        if (count == 2) second = p;
        p = p->next;
        ++count;
    }
    p->next = second;
    cout << (list.hasCycle() ? "true" : "false") << endl;
    return 0;
}
