class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int t = 0, d = matrix.size()-1, l = 0, r = matrix[0].size()-1;
        vector<int> ans;


        while(t<=d && l<=r){
            // left->right top
            for(int i=l; i<=r; i++){
                ans.push_back(matrix[t][i]);
            }
            t++;
            // top->down right
            for(int i=t; i<=d; i++){
                ans.push_back(matrix[i][r]);
            }
            r--;
            if(t<=d){
            //right->left
                for(int i=r; i>=l; i--){
                    ans.push_back(matrix[d][i]);
                }
                d--;
            }
            //bot->up
            if(l<=r){
                for(int i=d; i>=t; i--){
                    ans.push_back(matrix[i][l]);
                }
                l++;
            }
        }
        return ans;
        
    }
};
