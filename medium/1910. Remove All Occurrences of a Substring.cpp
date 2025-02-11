class Solution {
public:
    string removeOccurrences(string s, string part) {
        size_t pos = s.find(part);
        if(pos == string::npos){
            return s;
        }else{
            s.erase(pos, part.size());
            s = removeOccurrences(s, part);
            return s;
        }
    }
};
