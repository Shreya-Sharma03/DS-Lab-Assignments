#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data = val;
        left = right = nullptr;
    }
};
class BST{
private:
    Node *root;
    Node *insert(Node *node, int val){
        if (!node) return new Node(val);
        if (val < node->data) node->left = insert(node->left, val);
        else if (val > node->data) node->right = insert(node->right, val);
        return node;
    }
    Node *search(Node *node, int key){
        if (!node || node->data == key) return node;
        if (key < node->data) return search(node->left, key);
        return search(node->right, key);
    }
    Node *findMin(Node *node){
        while (node && node->left) node = node->left;
        return node;
    }
    Node *findMax(Node *node){
        while (node && node->right) node = node->right;
        return node;
    }
public:
    BST() { root = nullptr; }
    void insert(int val) { root = insert(root, val); }
    Node *search(int key) { return search(root, key); }
    Node *searchIter(int key){
        Node *curr = root;
        while (curr){
            if (curr->data == key) return curr;
            else if (key < curr->data) curr = curr->left;
            else curr = curr->right;
        }
        return nullptr;
    }
    Node *getMin() { return findMin(root); }
    Node *getMax() { return findMax(root); }
    Node *getRoot() { return root; }
    Node *inorderSuccessor(Node *target){
        if (!target) return nullptr;
        if (target->right) return findMin(target->right);
        Node *succ = nullptr;
        Node *curr = root;
        while (curr){
            if (target->data < curr->data){
                succ = curr;
                curr = curr->left;
            }
            else if (target->data > curr->data){
                curr = curr->right;
            }
            else break;
        }
        return succ;
    }
    Node *inorderPredecessor(Node *target){
        if (!target) return nullptr;
        if (target->left) return findMax(target->left);
        Node *pred = nullptr;
        Node *curr = root;
        while (curr){
            if (target->data > curr->data){
                pred = curr;
                curr = curr->right;
            }
            else if (target->data < curr->data){
                curr = curr->left;
            }
            else break;
        }
        return pred;
    }
};
int main(){
    BST bst;
    int values[] = {20, 10, 30, 5, 15, 25, 35};
    for (int v : values)
        bst.insert(v);
    cout << "Recursive Search for 15: "
         << (bst.search(15) ? "Found" : "Not Found") << endl;
    cout << "Iterative Search for 25: "
         << (bst.searchIter(25) ? "Found" : "Not Found") << endl;
    cout << "Minimum element: "
         << (bst.getMin() ? bst.getMin()->data : -1) << endl;
    cout << "Maximum element: "
         << (bst.getMax() ? bst.getMax()->data : -1) << endl;
    Node *target = bst.search(20);
    Node *succ = bst.inorderSuccessor(target);
    Node *pred = bst.inorderPredecessor(target);
    cout << "Inorder Successor of 20: ";
    if (succ) cout << succ->data << endl;
    else cout << "None" << endl;
    cout << "Inorder Predecessor of 20: ";
    if (pred) cout << pred->data << endl;
    else cout << "None" << endl;
    return 0;
}
