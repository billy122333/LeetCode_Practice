class Solution {
public:
    void subset(vector<vector<int>>& ans, vector<int>& candidates, vector<int> cur, int i, int target ){
        if(target == 0)
            ans.push_back(cur);
        if(target <0)
            return;
        for(;i<candidates.size();i++){
            if(candidates[i] > target)
                continue;
            cur.push_back(candidates[i]);
            subset(ans, candidates, cur, i, target-candidates[i]);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        subset(ans, candidates, cur, 0, target);
        return ans;
    }

};
