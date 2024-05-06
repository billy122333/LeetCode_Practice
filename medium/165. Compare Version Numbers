
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int s1 = version1.size(), s2 =version2.size();
        int s1_pt = 0, s2_pt=0;
        int num1 =0, num2 = 0;
        while(s1_pt < s1 || s2_pt < s2){
            
            while(s1_pt < s1 && version1[s1_pt] != '.' ){
                num1 = 10*num1 + (version1[s1_pt] - '0');
                s1_pt++;
            }
            while(s2_pt < s2 && version2[s2_pt] != '.'){
                num2 = 10*num2 + (version2[s2_pt] - '0');
                s2_pt++;
            }
                
            if(num1>num2)
                return 1;
            else if(num1<num2)
                return -1;
            num1 = 0, num2 = 0;
            s1_pt++;
            s2_pt++;
        }
        return 0;
    };
};
