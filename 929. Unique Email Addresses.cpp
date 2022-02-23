class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> ans_set;
        for(int i = 0; i < emails.size(); i++){
            int j = 0;
            string tmp = "";
            bool ignore = false;
            for(; j < emails[i].length(); j++){
                if(emails[i][j] == '@'){
                    break;
                }else if(emails[i][j] == '.'){
                    continue;
                }else if(emails[i][j] == '+'){
                    ignore = true;
                    continue;
                }else if (!ignore){
                    tmp += emails[i][j];
                }else{
                    continue;
                }
            }
            tmp = tmp.append(emails[i], j, emails[i].length()-1);
            ans_set.insert(tmp);
        }
        return ans_set.size();
    }
};
