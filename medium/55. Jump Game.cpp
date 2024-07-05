class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;
        vector<int> canReach(nums.size()-1, 0);
        canReach[0] = nums[0];
        
        for(int i =1; i<n-1; i++){
            // if i > canReach[i-1], it means the previous jump can't reach position i
            if(i > canReach[i-1]) return false;
            // the max distance that can jump from previous to i
            canReach[i] = max(canReach[i-1], i+nums[i]);
            if(canReach[i] >= n-1)
                return true;
        }
        // for n=2, it won't go into the loop
        return canReach[n-2] >= n-1 ? true : false;
        
    }
};
