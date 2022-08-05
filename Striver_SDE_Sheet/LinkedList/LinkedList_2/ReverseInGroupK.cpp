#include <iostream>
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
 if(head == NULL||head->next == NULL) return head;
        
    ListNode* dummy = new ListNode();
    dummy->val = -1;
    dummy->next = head;
        
    ListNode* pre = dummy;
    ListNode* cur;  
    ListNode* nex;
        
    int length = 0;
    while(head != NULL) {
        head = head->next;
        length++;
    }
    while(length >= k) {
        cur = pre->next;
        nex = cur->next;
        for(int i=1;i<k;i++) {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        length =length - k;
    }
    return dummy->next;
    }
};