/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

    ListNode* reverseList(ListNode* head){
     ListNode* nxt=NULL;
     ListNode* prev=NULL;
     ListNode* cur=head;
     while(cur!=NULL){
     nxt=cur->next;
     cur->next=prev;
     prev=cur;
     cur=nxt;
     }
     return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
         fast=fast->next->next;
         slow=slow->next;
        }
        ListNode* t=head;
        slow->next=reverseList(slow->next);
        slow=slow->next;
        while(slow!=NULL){
         if(t->val!=slow->val)return false;
         t=t->next;
         slow=slow->next;
        }
        return true;
    }
};
