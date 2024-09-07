class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for(char c:s){
            if(c == '(' || c == '[' || c == '{'){
                stk.push(c);
            }else{
                char tmp ;
                if(!stk.empty()){
                    tmp = stk.top();
                    stk.pop();
                }else{
                    return false;
                }
                switch(c){
                    case ')':
                        if(tmp != '(')
                            return false;
                        break;
                    case ']':
                        if(tmp != '[')
                            return false;
                        break;
                    case '}':
                        if(tmp != '{')
                            return false;
                        break;
                }
            }
        }
        if(stk.size() > 0)
            return false;
        return true;
    }
};
