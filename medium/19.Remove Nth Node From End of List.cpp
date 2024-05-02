class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* pre = dummy, *form = dummy;
        
        while(n--)
            form = form -> next;
        
        while(form->next !=nullptr){
            pre = pre -> next;
            form = form->next;
        }
        pre -> next = pre -> next ->next;
        
        return dummy->next;
    }
};
