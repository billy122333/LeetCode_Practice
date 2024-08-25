struct cmp {
    bool operator() (const vector<int>& a, const int b) {
        return a[1] < b;
    }
};

class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int len) {
        int n = tiles.size(), total = 0;
        sort(tiles.begin(), tiles.end());
        
        vector<int> nums(n);
        for(int i=0; i<n; i++) {
            nums[i] = total;
            total += tiles[i][1] - tiles[i][0] + 1;
        }

        int ret = 0;

        for(int i=0; i<n; i++) {
            int start = tiles[i][0];
            int end = start + len - 1;
            // 不小於end的第一個tiles[j][1]
            int j = lower_bound(tiles.begin(), tiles.end(), end, cmp()) - tiles.begin();
            if(j == n) {
                ret = max(ret, total - nums[i]);
                break;
            }
            
            //若end > tile[j]的起點，則把覆蓋到的部分加入(並+1 因為是閉區間)
            int re = (end >= tiles[j][0] ) ? end - tiles[j][0] + 1 : 0;
            ret = max(ret, nums[j] - nums[i] + re);

        }

        return ret;
    }
};
