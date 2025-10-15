#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int value){
        data=value;
        next=prev=NULL;
    }
};
class DoublyLinkedList{
    private:
    Node* head;
    public:
    DoublyLinkedList(){
        head=NULL;
    }
    void insertAtBeginning(int value){
        Node* newNode= new Node(value);
        if(head){
            newNode->next=head;
            head->prev=newNode;
        }
        head=newNode;
    }
    void insertAtEnd(int value){
        Node* newNode= new Node(value);
        if(!head){
            head=newNode;
            return;
        }
        Node* temp=head;
        while(temp->next) temp=temp->next;
        temp->next=newNode;
        newNode->prev=temp;
    }
    void insertAfter(int target, int value){
        Node* temp=head;
        while(temp !=NULL && temp->data!=target)
            temp=temp->next;
        if(temp==NULL){
            cout<<"Target node not found\n";
            return;
        }
        Node* newNode=new Node(value);
        newNode->next=temp->next;
        newNode->prev=temp;
        if (temp->next) temp->next->prev=newNode;
        temp->next=newNode;
    }
    void insertBefore(int target, int value){
        Node* temp=head;
        if (!temp) return;
        if (temp->data==target){
            insertAtBeginning(value);
            return;
        }
        while(temp!= NULL && temp->data!=target) temp=temp->next;
        if(temp==NULL){
            cout<<"Target node not found.\n";
            return;
        }
        Node* newNode= new Node(value);
        newNode->next=temp;
        newNode->prev=temp->prev;
        temp->prev->next=newNode;
        temp->prev=newNode;
    }
    void deleteNode(int value){
        Node* temp=head;
        while(temp!=NULL && temp->data!=value) temp=temp->next;
        if(temp==NULL){
            cout<<"Node not found\n";
            return;
        }
        if(temp->prev) temp->prev->next=temp->next;
        else head=temp->next;
        if(temp->next) temp->next->prev=temp->prev;
        delete temp;
        cout<<"Node deleted\n";
    }
    void searchNode(int value){
        Node* temp=head;
        while(temp){
            if(temp->data==value){
                cout<<"Node found"<<endl;
                return;
            }
            temp=temp->next;
        }
        cout<<"Node not found\n";
    }
    void display(){
        Node* temp=head;
        cout<<"List\n";
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    DoublyLinkedList dll;
    int choice,val,target;
    while(true){
        cout<<"1.Insert at beginning\n";
        cout<<"2.Insert at end\n";
        cout<<"3.Insert after a node\n";
        cout<<"4.Insert before a node\n";
        cout<<"5.Delete a node\n";
        cout<<"6.Search for a node\n";
        cout<<"7.Display list\n";
        cout<<"8.Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
            cout<<"Enter value: ";
            cin>>val;
            dll.insertAtBeginning(val);
            break;
            case 2:
            cout<<"Enter value: ";
            cin>>val;
            dll.insertAtEnd(val);
            break;
            case 3:
            cout<<"Enter target node value: ";
            cin>>target;
            cout<<"Enter new value: ";
            cin>>val;
            dll.insertAfter(target,val);
            break;
            case 4:
            cout<<"Enter target node value: ";
            cin>>target;
            cout<<"Enter new value: ";
            cin>>val;
            dll.insertBefore(target,val);
            break;
            case 5:
            cout << "Enter value to delete: ";
            cin >> val;
            dll.deleteNode(val);
            break;
            case 6:
            cout << "Enter value to search: ";
            cin >> val;
            dll.searchNode(val);
            break;
            case 7:
            dll.display();
            break;
            case 8:
            return 0;
            default:
            cout<<"Invalid choice.\n";
        }
    }
    return 0;
}