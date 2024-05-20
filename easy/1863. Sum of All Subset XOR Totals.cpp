class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return helper(nums, 0, 0);
    }
    int helper(vector<int>& nums, int level, int sum){
        if(level == nums.size()) return sum;
        int include = helper(nums, level+1, sum ^ nums[level]);
        int exclude = helper(nums, level+1, sum);
        return include + exclude;
    }
};
