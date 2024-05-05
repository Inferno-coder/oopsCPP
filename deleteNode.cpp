void deleteNode(ListNode* node) {
        if(node->next==NULL)node=NULL;
        else
        {
            node->val=node->next->val;
            node->next=node->next->next;
        }
}
