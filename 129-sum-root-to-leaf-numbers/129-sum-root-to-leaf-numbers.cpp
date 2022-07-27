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
    int ans=0;
    void dfs(TreeNode*root,int val){
        if(!root)return;
        val*=10;
        val+=root->val;
        if(!root->left and !root->right)ans+=val;
        dfs(root->left,val);
        dfs(root->right,val);
    }
public:
    // void solve(TreeNode*root,int &sum,string s){
    //     if(!root)return;
    //     if(!root->left and !root->right)sum+=stoi(s);
    //     if(root->left)solve(root->left,sum,s+to_string(root->left->val));
    //     if(root->right)solve(root->right,sum,s+to_string(root->right->val));
    // }
    
    int sumNumbers(TreeNode* root) {
        if(!root)return ans;
        dfs(root,0);
        return ans;
        // int sum=0;
        // solve(root,sum,to_string(root->val));
        // return sum;
    }
};