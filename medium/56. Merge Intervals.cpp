class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> prev= intervals[0];
        
        for(int i=1; i<intervals.size(); i++){
            vector<int> cur = intervals[i];
            // prev end > cur start -> overlap
            if(prev[1] >= cur[0]){
                prev[1] = max(prev[1], cur[1]);
            }else{
                ans.push_back(prev);
                prev = cur;
            }
        }
        ans.push_back(prev);
        return ans;
    }
    
};
