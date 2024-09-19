bool myCompare(vector<int> a,vector<int> b){
    return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ansIntervals;
        if(intervals.size()<1){
            ansIntervals.push_back(newInterval);
            return ansIntervals;
        }
        // find the position of the newInterval with the start
        auto it = lower_bound(intervals.begin(), intervals.end(), newInterval, myCompare);
        intervals.insert(it, newInterval);

        // key points
        ansIntervals.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            if( ansIntervals.back()[1] >= intervals[i][0]){
                ansIntervals.back()[1] = max(ansIntervals.back()[1], intervals[i][1]);
            }else{
                ansIntervals.push_back(intervals[i]);
            }
        }
        return ansIntervals;
    }
};
