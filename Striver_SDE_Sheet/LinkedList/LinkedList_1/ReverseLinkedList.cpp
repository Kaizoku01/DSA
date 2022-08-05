#include "bits/stdc++.h";
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class linkedList{
    public:
    Node* head;
    linkedList(){
        head = NULL;
    }

    //! Reverse 
    void reverseList() {
        Node* current = head;
        Node* prev = NULL;
        Node* newNext;
        
        while(current != NULL){
            newNext = current->next;
            current->next = prev;
            
            prev = current;
            current = newNext;
        }
        head = prev;
    }
    //! Reverse using recursion
    // Node* reverseList(Node* head) {
      
    // if(head ==NULL || head->next ==NULL)
    //     return head;
    
    // Node* node = reverseList(head->next);
    // head->next->next = head;
    // head->next = NULL;
        
    // return node;
    // }
    //print
        void print()
    {
        struct Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    //insert
    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }

};


int main(){
    linkedList ll;
    ll.push(1);
    ll.push(2);
    ll.push(3);
    ll.print();
    // ll.reverseList();
    // cout<<endl;
    // ll.print();
}


