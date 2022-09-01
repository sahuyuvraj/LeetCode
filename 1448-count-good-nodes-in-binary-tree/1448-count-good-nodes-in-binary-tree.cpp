/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans;
    void solve(TreeNode*root,int val){
        if(!root)return;
        if(root->left){
            if(root->left->val>=val){
                ans++;
                solve(root->left,root->left->val);
            }else{
                solve(root->left,val);
            }
        }
    
        if(root->right){
            if(root->right->val>=val){
                ans++;
                solve(root->right,root->right->val);
            }else{
                solve(root->right,val);
            }
        }
    }
    int goodNodes(TreeNode* root) {
        ans=1;
        if(!root)return 0;
        solve(root,root->val);
        return ans;
    }
};