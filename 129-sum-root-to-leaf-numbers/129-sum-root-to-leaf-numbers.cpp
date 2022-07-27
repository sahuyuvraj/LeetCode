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
    int ans=0;
    
    void sum(TreeNode*root,int val){
        if(!root)return;
        val*=10;
        val+=root->val;
        if(!root->left and !root->right)ans+=val;
        sum(root->left,val);
        sum(root->right,val);
    }
    int sumNumbers(TreeNode* root) {
        sum(root,0);
        return ans;
    }
};