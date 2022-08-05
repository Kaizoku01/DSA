#include "bits/stdc++.h"
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
    //! Naive
    //* TC = O(N) SC = O(N)
    // Node *detectCycle(Node *head) {
    //     unordered_set<Node*> hashSet;
    //     while(head != NULL){
    //         if(hashSet.find(head) != hashSet.end()) return head;
    //         hashSet.insert(head);
    //         head = head->next;
    //     }  
    //     return NULL;
    // }
    //! optimized
    //* TC = O(N)  SC = O(1)
    Node *detectCycle(Node *head) {
        if(head == NULL || head->next == NULL) return NULL;
        Node* slow = head, *fast = head,*hero = head;
        bool flag = false;
        while(fast->next != NULL && fast->next->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                while(slow != hero){
                    slow = slow->next;
                    hero = hero->next;
                }
                return slow;
            }
        }
        return NULL;
    }
    //print
    void print(){
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
    ll.push(2);
    ll.push(1); 
  
}


