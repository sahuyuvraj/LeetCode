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
    
    void solve(TreeNode*root,int flg,int count){
        if(!root)return;
        //ans=max(ans,count);
        if(flg==0){
            solve(root->left,0,1);
            solve(root->right,1,count+1);
        }
        if(flg==1){
            solve(root->left,0,count+1);
            solve(root->right,1,1);
        }
        ans=max(ans,count);
    }
    
    int longestZigZag(TreeNode* root) {
        ans=0;
        solve(root,0,0);
        solve(root,1,0);
        return ans;
    }
};