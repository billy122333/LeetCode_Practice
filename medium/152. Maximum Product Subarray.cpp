class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int _max = nums[0];
        int r = nums[0];
        float imax = r, imin = r;
        
        
        for(int i = 1; i<nums.size(); ++i){
            if(nums[i] < 0){
                swap(imax,imin);
            }
            imax = max(imax*nums[i], float(nums[i]));
            imin = min(imin*nums[i], float(nums[i]));
            cout << imin << endl;

            _max = max(float(_max), imax);
        }
        return _max;
    }
};
