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
    bool inorder(TreeNode*root,unordered_map<int,int>&mp,int k){
        if(!root)return false;
        int data=root->val;
        if(mp[k-data]){
           return true;
        }
        mp[data]++;
        return inorder(root->left,mp,k) or inorder(root->right,mp,k);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int>mp;
        return inorder(root,mp,k);
    }
};