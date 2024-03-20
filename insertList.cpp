class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* t1=list1;
        ListNode* t2=list1;
        while((a-1)>0 && t1->next){
        t1=t1->next;
        a--;
        }
        while((b+1)>0 && t2->next){
        t2=t2->next;
        b--;
        }
        t1->next=list2;
        ListNode* tail=list2;
        while(tail->next)tail=tail->next;
        tail->next=t2;
        return list1;
    }
};
