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
    int ans=-2;
    
    void solve(TreeNode*root,int h){
        if(!root)return;
        if(h==1 and ans==-2){ans=root->val;return;}
        solve(root->left,h-1);
        solve(root->right,h-1);
    }
    
    int h(TreeNode*root){
        if(!root)return 0;
        return max(h(root->left),h(root->right))+1;
    }
    int findBottomLeftValue(TreeNode* root) {
        int height=h(root);
        if(height==1)return root->val;
        solve(root,height);
        return ans;
    }
};