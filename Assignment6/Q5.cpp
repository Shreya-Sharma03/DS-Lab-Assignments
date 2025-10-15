// 5. Write a program to check if a linked list is Circular Linked List or not.
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};
Node *newNode(int data){
    Node* temp=new Node;
    temp->data=data;
    temp->next=NULL;
    return temp;
}
bool isCircular(Node* head){
    if (head==NULL) return true;
    Node* node=head->next;
    while(node!=NULL && node!=head) node=node->next;
    return (node==head);
}
int main(){
    Node* head=newNode(1);
    head->next=newNode(2);
    head->next->next=newNode(3);
    head->next->next->next=newNode(4);
    isCircular(head) ? cout<<"Yes\n" : cout<<"No\n";
    head->next->next->next->next=head;
    isCircular(head) ? cout<<"Yes\n" : cout<<"No\n";
    return 0;
}