class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> alphabet;
        int left = 0;
        int right = 1;
        int maxf = 1;
        int maxl = 1;
        alphabet[s[left]]++;
        
        while(right<s.length()){
            int windowSize = right-left+1;
            if(++alphabet[s[right]] > maxf)
                maxf = alphabet[s[right]];
            if(windowSize - maxf > k){
                alphabet[s[left]]--;
                left++;
            }else{
                maxl = max(maxl, windowSize);
            }
            right++;
        }
        return maxl;
    }
};
