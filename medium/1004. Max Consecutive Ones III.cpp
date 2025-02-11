class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zero = 0;
        int maxl = 0;
        int left = 0;

        for(int right=0; right<nums.size(); right++){
            if(nums[right] == 0){
                zero++;
            }
            int windowSize = right-left+1;
            if(zero>k){
                if(nums[left] == 0){
                    zero--;
                }
                left++;
            }else{
                maxl = max(maxl, windowSize);
            }
        }
        return maxl;
    }
};
