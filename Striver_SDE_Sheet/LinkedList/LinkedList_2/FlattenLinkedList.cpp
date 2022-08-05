#include "bits/stdc++.h";
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* bottom;

    Node(int data){
        this->data = data;
        next = NULL;
        bottom = NULL;
    }
};

class linkedList{
    public:
    Node* head;
    linkedList(){
        head = NULL;
    }

    Node* mergeLinkedList(Node* a , Node* b){
        Node* temp = new Node(0);
        Node* res = temp;

        while(a != NULL && b != NULL){
            if(a->data > b->data){
                temp->bottom = a;
                temp = temp->bottom;
                a = a->bottom;
            }
            else{
                temp->bottom = b;
                temp = temp->bottom;
                b = b->bottom;
            }
        }

        if(a) temp->bottom = a;
        else temp->bottom = b;

        return res->bottom;
    }

    Node* flatten(Node* root){
        if(root == NULL || root->next == NULL) return root;

        root->next = flatten(root->next);

        root = mergeLinkedList(root,root->next);


        return root;
    }

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
}