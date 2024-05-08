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
    ListNode* removeNodes(ListNode* head) {
        // ListNode *dummy = new ListNode(-1, head);
        ListNode *tmp = head;
        vector<int> ans;
        stack<int> st;
        int min;
        while(tmp!= nullptr){
            st.push(tmp->val);
            tmp = tmp->next;
        }
        min = st.top();
        ans.push_back(min);
        st.pop();
        while(!st.empty()){
            if(st.top() < min)
                st.pop();
            else{
                min = st.top();
                st.pop();
                ans.push_back(min);
            }
        }
        ListNode *dummy = new ListNode(-1, head);
        tmp = dummy;
        for(int i=ans.size()-1; i>=0; --i){
            tmp = tmp->next;
            tmp->val = ans[i];
            
        }
        tmp->next = nullptr;
        return dummy->next;
    }
};
