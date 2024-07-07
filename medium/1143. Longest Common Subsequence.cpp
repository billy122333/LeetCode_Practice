class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[text1.size()+1][text2.size()+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i=1; i<=text1.size(); i++){
            for(int j=1; j<=text2.size(); j++){
                // if text1[i] == text2[j], 則+1
                if(text1.at(i-1) == text2.at(j-1)){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                // 否則取左右最大
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};
