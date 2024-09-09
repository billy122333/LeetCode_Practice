class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;

        while(left<=right){
            int mid = (right-left)/2 + left;
            cout << nums[mid]<<endl;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target){
                if(target < nums[right] || nums[mid] > nums[left])
                    left = mid+1;
                else if(target > nums[right]){
                    right = mid-1;
                }else{
                    return right;
                }
            }else{
                if(target > nums[left] || nums[mid] < nums[right])
                    right = mid-1;
                else if(target < nums[left]){
                    left = mid+1;
                }else{
                    return left;
                }
            }
        }
        return -1;
    }
};
