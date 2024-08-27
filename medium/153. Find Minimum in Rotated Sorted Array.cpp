class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        while(l<r){
            int mid = (r-l)/2 + l;
            if(nums[mid]>=nums[r]){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        return nums[l];
    }
};153. Find Minimum in Rotated Sorted Array
