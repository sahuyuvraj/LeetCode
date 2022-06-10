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
    bool solve(TreeNode*root,int cnt,int sum){
        if(!root)return false;
        if(!root->left and !root->right and cnt+root->val==sum)return true;
        return solve(root->left,cnt+root->val,sum) or solve(root->right,cnt+root->val,sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root,0,targetSum);
    }
};