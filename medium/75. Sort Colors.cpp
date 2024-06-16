class Solution {
public:
    void sortColors(vector<int>& nums) {
        int colors[3];
        for(int i=0; i<nums.size(); i++){
            colors[nums[i]]++;
        }
        int count = 0;
        for(int i=0; i<3;i++){
            fill(nums.begin()+count, nums.begin()+count+colors[i], i);
            count+=colors[i];
        }
    }
};
