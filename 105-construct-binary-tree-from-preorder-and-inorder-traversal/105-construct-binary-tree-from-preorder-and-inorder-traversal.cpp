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
    int index=0;
    TreeNode*build(vector<int>&pre,vector<int>&in,int start,int end){
        if(start>end)return NULL;
        int i;
        for(i=start;i<=end;i++)if(in[i]==pre[index])break;
        TreeNode*root=new TreeNode(pre[index++]);
        root->left=build(pre,in,start,i-1);
        root->right=build(pre,in,i+1,end);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        index=0;
        return build(pre,in,0,pre.size()-1);
    }
};