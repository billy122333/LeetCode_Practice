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
    ListNode* doubleIt(ListNode* head) {
        ListNode* cur = nullptr;
        ListNode* prev = nullptr;
        if(head->val >= 5)
            cur = new ListNode(0, head);
        else
            cur = head;
        
        while(cur!=nullptr){
            swap(cur->next, prev);
            swap(cur, prev);
        }
        bool carry = false; 
        
        cur = prev;
        while(cur!=nullptr){
            int tmp_val = 0;
            tmp_val = cur->val *2;
            if(carry){
                tmp_val++;
                carry = false;
            }
            if(tmp_val>=10){
                tmp_val %= 10;
                carry = true;
            }
            cur->val = tmp_val;
            cur = cur->next;
        }
        
        cur = prev; prev = nullptr;
        while(cur!=nullptr){
            swap(cur->next, prev);
            swap(cur, prev);
        }
        return prev;
    }
};
