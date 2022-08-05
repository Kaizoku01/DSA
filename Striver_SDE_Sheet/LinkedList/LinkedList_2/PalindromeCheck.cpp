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


    //! Palindrome 
    //*TC = O(2N)   SC = O(N)
    // bool palindromeCheck(){
    //     vector<int> dummy;
    //     while(head != NULL){
    //         dummy.push_back(head->data);
    //         head = head->next;
    //     }
    //     if(dummy.size() == 1){
    //         return true;
    //     }
    //     for(int i=0;i<dummy.size()/2;i++){
    //         if(dummy[i] != dummy[(dummy.size() - (i + 1))]){
    //              return false;
    //         }
         
    //     }
    //     return true;
    // }

    //! Optimized
    //* TC = O(3N/2)  SC = O(1)
    bool palindromeCheck(){
        //mid ele
        Node* slow = head, *fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        //reverse
        Node* pre = NULL;
        Node* nex = NULL;
        while(slow->next != NULL){
            nex = slow->next->next;
            slow->next->next = pre;
            pre = slow->next;
            slow->next = nex;
        }
        //checking
        slow->next = pre;
        slow = slow->next;
        Node* dummy = head;
        while(slow!= NULL){
            if(dummy->data != slow->data){
                return false;
            }
            dummy = dummy->next;
            slow = slow->next;
        }
        return true;
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
    cout<<"\n "<<ll.palindromeCheck();
  
}


