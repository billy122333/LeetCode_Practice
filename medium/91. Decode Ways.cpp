class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0'){
            return 0;
        }
        vector<int> dp(s.length()+2, 0);
        dp[0] = 1;
        dp[1] = 1;
        // be careful to the index of s.
        for(int i=2; i<=s.length(); i++){
            int onedigit = s[i-1] - '0';
            int twodigit = stoi(s.substr(i-2, 2));
            // cout << (s[i-1]-'0') << "||" << (s[i]-'0') <<endl;
            if(onedigit != 0){
                dp[i] += dp[i-1];
            }
            if(10<=twodigit && twodigit<=26){
                dp[i] += dp[i-2];
            }
        }
        return dp[s.size()];
    }
};
