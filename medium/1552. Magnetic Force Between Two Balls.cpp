class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int ans = 0;
        if(position.size() == 1)
            return 0;
        sort(position.begin(), position.end());
        int l = 0, r = position[position.size()-1] - position[0];
        while(l <= r){
            int mid = l + (r-l)/2 ; 
            if(can_load(position, m, mid)){
                ans = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return ans;
    }
    bool can_load(vector<int> &position, int m, int dist){
        int valid_balls = 1;
        int prev = position[0];
        for(int i=1; i<position.size(); i++){
            if(position[i]-prev >= dist){
                valid_balls++;
                prev = position[i];
            }
            if(valid_balls>= m)
                return true;
        }
        return false;
    }
};
