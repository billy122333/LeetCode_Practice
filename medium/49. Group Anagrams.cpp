class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> stmp;
        vector<vector<string>> groups;
        for(auto s: strs){
            string tmp = s;
            sort(s.begin(), s.end());
            // 只要stmp[s].push_back(tmp); 就可以了
            auto it = stmp.find(s);
            if(it == stmp.end()){
                vector<string> group;
                group.push_back(tmp);
                stmp[s] = group;
            }else{
                it->second.push_back(tmp);
            }
        }
        for (auto it = stmp.begin(); it != stmp.end(); ++it) {
            groups.push_back(it->second);
        }
        // 可以使用auto push就好
        // for(auto x: stmp){
        //     groups.push_back(x.second);
        // }
        return groups;
    }
};
