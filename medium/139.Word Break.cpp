class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        
        for(int i=1; i<=s.size(); i++){
            for(string word:wordDict){
                // dp[i] 為i減去字母長度 & dp[start]是否為true?

                int start = i - word.size();
                if(start>=0 && dp[start] && s.substr(start, word.size()) == word){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

/*
    一個字串長度的dp，前一格存目前還需要的字
*/
