// binary search
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for(int i=0; i<nums.size(); i++){
            if(sub.size()==0 || sub[sub.size()-1] < nums[i]){
                sub.push_back(nums[i]);
            }
            else{
                vector<int>::iterator j = lower_bound(sub.begin(), sub.end(), nums[i]);
                *j = nums[i];
            }
        }
        return sub.size();
    }
};

// 二分搜索替換：如果 x 不大於 sub 的最後一個元素，我們不能簡單地擴展 sub。
// 此時，我們使用二分搜索在 sub 中找到第一個大於或等於 x 的位置，並用 x 替換該位置的元素。
// 這樣做的原因是，我們希望保持 sub 的長度不變，但有潛力在未來構建更長的遞增子序列。

// 自己的理解 : 我曾出現過這種長度的Increasing subsequece 所以不會影響答案長度，只是用來存有沒有機會有更長的出現

// DP
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    // dp[i] 代表以我為end
    vector<int> dp(nums.size(),1);

    for(int i=0; i<nums.size(); i++){
        for(int j=0; j<i; j++){
            if(nums[j] < nums[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());

        
    }
};
