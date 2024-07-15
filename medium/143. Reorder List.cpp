class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* tmp = head;
        vector<int> nums;
        while(tmp!=nullptr){
            nums.push_back(tmp->val);
            tmp = tmp->next;
        }
        int i = 0;
        int j = nums.size()-1;
        int count = 0;
        for(tmp = head; tmp!=nullptr; count++, tmp=tmp->next){
            if(!(count%2)){
                tmp -> val = nums[i];
                ++i;
            }else{
                tmp->val = nums[j];
                --j;
            }
        }

    }
};
