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
    
    void solve(TreeNode*root,int sum,vector<int>&v){
        if(!root)return;
        v.push_back(root->val);
        solve(root->left,sum,v);
        solve(root->right,sum,v);
        
        long long t=0;
        for(int i=v.size()-1;i>=0;i--){
            t+=v[i];
            if(t==sum)ans++;
        }
        v.pop_back();

    }
    
    int pathSum(TreeNode* root, int targetSum) {
        ans=0;
        vector<int>v;
        solve(root,targetSum,v);
        return ans;
    }
};