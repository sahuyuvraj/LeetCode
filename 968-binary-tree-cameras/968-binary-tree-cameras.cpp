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
    int dfs(TreeNode*root,int &ans){
        if(!root)return 2;
        int left=dfs(root->left,ans),right=dfs(root->right,ans);
        if(!left or !right){
            ans++;
            return 1;
        }
        return (left==1 or right==1)?2:0;
    }

    int minCameraCover(TreeNode* root) {
        int ans=0;
        return (dfs(root,ans)?0:1)+ans;
    }
};