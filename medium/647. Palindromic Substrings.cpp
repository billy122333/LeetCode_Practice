class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int count = 0;
        
        // for one letter
        for(int i=0; i<s.size(); i++){
            dp[i][i] = true;
            count ++;
        }
        
        // for two letters
        for(int i=0; i<s.size()-1; i++){
            dp[i][i+1] = (s[i]==s[i+1]);
            count += dp[i][i+1];
        }
        
        // for over two letters
        for(int length=3; length<=s.size(); length++){
            for(int i=0, j=length-1; j<s.size() ;i++,j++){
                dp[i][j] = dp[i+1][j-1] && s[i]==s[j];
                count += dp[i][j];
            }            
        }
        return count;
        
    }
};
