class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        findsubset(nums, subset, ans, 0);
        return ans;
    }
    void findsubset(vector<int>& nums, vector<int>& subset, vector<vector<int>>& ans, int level){
        ans.push_back(subset);
        for(int i = level; i< nums.size(); i++){
            // include
            subset.push_back(nums[i]);
            findsubset(nums, subset, ans, i+1);
            // exclude
            subset.pop_back();
        }
    }
};
