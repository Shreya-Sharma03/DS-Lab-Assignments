/*You are given a binary tree (not a binary search tree). Write a program to check if
the tree contains any duplicate node values using hash set.
Your task is to:
1. Return true (or print "Duplicates Found") if there exists at least one duplicate value.
2. Otherwise, return false (or print "No Duplicates").*/
#include <iostream>
#include <unordered_set>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};
class BinaryTree {
public:
    Node* root;
    BinaryTree() : root(nullptr) {}
    bool hasDuplicate() {
        unordered_set<int> seen;
        return hasDuplicateUtil(root, seen);
    }
private:
    bool hasDuplicateUtil(Node* node, unordered_set<int>& seen) {
        if (node == nullptr) return false;
        if (seen.find(node->data) != seen.end()) {
            return true;
        }
        seen.insert(node->data);
        return hasDuplicateUtil(node->left, seen)
            || hasDuplicateUtil(node->right, seen);
    }
};
int main() {
    BinaryTree tree;
    tree.root = new Node(1);
    tree.root->left = new Node(2);
    tree.root->right = new Node(3);
    tree.root->right->right = new Node(2);
    cout << (tree.hasDuplicate() ? "Duplicates Found" : "No Duplicates") << endl;
    return 0;
}
