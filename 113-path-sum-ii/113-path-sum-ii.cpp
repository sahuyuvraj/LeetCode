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
    vector<vector<int>>ans;
    
    
    void solve(TreeNode*root,int targetSum,vector<int>&path){
        if(!root)return;
        path.push_back(root->val);
        if(!root->left and !root->right){
            if(targetSum==root->val)
            ans.push_back(path);
            path.pop_back();
            return;
        }

        solve(root->left,targetSum-root->val,path);
        solve(root->right,targetSum-root->val,path);
        path.pop_back();
        return;
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        ans.clear();
        vector<int>path;
        solve(root,targetSum,path);
        return ans;
    }
};