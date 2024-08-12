class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> um;
        for(int num: nums){
            um[num] = true;
        }
        // 是否為開頭
        for(int num:nums){
            if(um.count(num-1) > 0)
                um[num] = false;
        }
        int ans = 0;
        // 是開頭 且後面有人
        for(int num:nums){
            if(um[num]==true){
                int j=0, count=0;
                while(um.count(num+j) > 0){
                    j++;
                    count++;
                }
                if(count>ans){
                    ans = count;
                }
            }
        }
        return ans;
    }
};
