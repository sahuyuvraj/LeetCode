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
    
    bool check(TreeNode*root,int n){
        if(!root)return true;
        if(root->val!=n)return false;
        return check(root->left,n) and check(root->right,n);
    }
    
    bool isUnivalTree(TreeNode* root) {
        if(!root)return true;
        int n=root->val;
        return check(root,n);
    }
};