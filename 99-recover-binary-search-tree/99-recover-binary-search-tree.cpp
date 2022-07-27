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
    
    TreeNode*prev=NULL,*first=NULL,*second=NULL;
    void find(TreeNode*root){
        if(!root)return;
        find(root->left);
        if(prev and root->val<prev->val){
            if(first==NULL)first=prev;
            second=root;
        }
        prev=root;
        find(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        find(root);
        swap(first->val,second->val);
    }
};