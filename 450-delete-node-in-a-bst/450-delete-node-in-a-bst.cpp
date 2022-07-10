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
    int minVal(TreeNode*root){
        TreeNode*temp=root;
        while(temp->left)temp=temp->left;
        return temp->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return root;
        if(root->val>key){
            root->left=deleteNode(root->left,key);
        }else if(root->val<key){
            root->right=deleteNode(root->right,key);
        }else{
            //case 1: if leaf node
            if(!root->left&&!root->right){
                delete root;
                return NULL;
            }
            
            //case 2:if have one child node
            else if(root->left&&!root->right){
                TreeNode*temp=root->left;
                delete root;
                return temp;
            }
            else if(!root->left&&root->right){
                TreeNode*temp=root->right;
                delete root;
                return temp;
            }
            
            //case 3: if have both child
            else{
                int min=minVal(root->right);
                root->val=min;
                root->right=deleteNode(root->right,min);
                return root;
            }
        }
        return root;
    }
};