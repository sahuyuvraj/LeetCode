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
    bool check(TreeNode*r1,TreeNode*r2){
        if(!r1 and !r2)return true;
        if(!r1 or !r2)return false;
        return (r1->val==r2->val) and check(r1->left,r2->right) and check(r2->left,r1->right);
    }
    
    bool isSymmetric(TreeNode* root) {
        return check(root->left,root->right);
    }
};