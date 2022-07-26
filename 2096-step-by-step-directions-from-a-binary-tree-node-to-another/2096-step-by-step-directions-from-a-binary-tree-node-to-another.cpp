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
    
    TreeNode*find(TreeNode*root,int start,int dest){
        if(!root) return NULL;
        if(root->val==start or root->val==dest)return root;
        TreeNode*left=find(root->left,start,dest);
        TreeNode*right=find(root->right,start,dest);
        if(left and right) return root;
        if(left) return left;
        return right;
    }
    
    
    bool path(TreeNode*root,int start,string &s){
        if(!root)return false;
        if(root->val==start)return true;
        
        s.push_back('L');
        if(path(root->left,start,s))return true;
        s.pop_back();
        
        s.push_back('R');
        if(path(root->right,start,s))return true;
        s.pop_back();
        return false;
        
         }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode*lca=find(root,startValue,destValue);
        string lca_to_a,lca_to_b;
        path(lca,startValue,lca_to_a);
        path(lca,destValue,lca_to_b);
        
        for(auto &e:lca_to_a) e='U';
        return lca_to_a+lca_to_b;
    }


};