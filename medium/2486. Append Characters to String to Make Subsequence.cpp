class Solution {
public:
    int appendCharacters(string s, string t) {
        int ssize = s.size(), tsize= t.size();
        int p1 = 0, p2 = 0;
        while(p1 < ssize){
            if(s[p1] == t[p2]){
                p1++;
                p2++;
            }else{
                p1++;
            }
        }
        return tsize-p2;
        
    }
};
