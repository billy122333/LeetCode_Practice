class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int globalMaxSum = nums[0];
        
        vector<int> maxSumArray(nums.size());
        maxSumArray[0] = nums[0];
        for (int ind = 1; ind < nums.size(); ind++) {
            // 2. max subarray ending with nums[i]
            // maxSumArray[ind-1] 可用常數取代
            maxSumArray[ind] = max(maxSumArray[ind-1] + nums[ind], nums[ind]);
            globalMaxSum = max(maxSumArray[ind], globalMaxSum);
        }
        return globalMaxSum;
    }
};
