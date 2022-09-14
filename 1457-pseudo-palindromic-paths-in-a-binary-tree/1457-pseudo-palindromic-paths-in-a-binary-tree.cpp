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
    int res=0;
    unordered_map<int,int> v;
    void fu(TreeNode* root)
    {
        if(root==nullptr)
            return;
        v[root->val]++;
        if(root->left==nullptr && root->right==nullptr)
        {
            int cnt=0;
            for(auto &i:v)
            {
                if(i.second%2)
                    cnt++;
                if(cnt>1)
                    break;
            }
            if(cnt<2)
                res++;
        }
        fu(root->left);
        fu(root->right);
        v[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        //vector<int> v;
        fu(root);
        return res;
    }
};