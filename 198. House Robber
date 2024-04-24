class Solution {
public:
    int rob(vector<int>& nums) {
        int lens = nums.size();
        if(lens==0)
            return 0;
        int prev1 = 0; 
        int prev2 = 0;
        // int money[100] = {0};
        // money[0] = nums[0];
        // money[1] = max(nums[0], nums[1]);
        for(int i=0;i<lens; i++){
            // money[i] = max(money[i-2]+nums[i], money[i-1]);
            int tmp = 0;
            tmp = max(prev2+nums[i], prev1);
            prev2 = prev1;
            prev1 = tmp;
        }
        return prev1;
    }
};
