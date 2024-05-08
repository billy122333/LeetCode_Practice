class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq;
        int sz = score.size();
        vector<string> ans(sz, "");
        
        int count = 1;
        for(int i=0; i<sz; i++){
            pq.push({score[i], i});
        }
        
        for(int i=1; i<=sz; i++){
            if(count==1)
                ans[pq.top().second]="Gold Medal";
            else if(count==2)
                ans[pq.top().second]="Silver Medal";
            else if(count==3)
                ans[pq.top().second]="Bronze Medal";
            else{
                ans[pq.top().second]=to_string(count);
            }
            pq.pop();
            count++;
        }

        return ans;
    }
};
