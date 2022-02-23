/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 */
class Solution {
public:
    int ans ;
    int kk;
    void Tranverse(TreeNode* root){
        if(root == nullptr || kk == 0 ){
            return;
        }
        Tranverse(root->left);
        if(--kk == 0){
            ans = root -> val;
            return;
        }
        Tranverse(root->right);
        
        
    }
    
    
    int kthSmallest(TreeNode* root, int k) {
        kk = k;
        Tranverse(root);
        return ans;
        
    }
    
};
