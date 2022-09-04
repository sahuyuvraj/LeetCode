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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<int>>mp;
        queue<pair<TreeNode*,int>>q;
        
        q.push({root,0});
        
        while(!q.empty()){
            int n=q.size();
            multiset<pair<int,int>>s;
            for(int i=0;i<n;i++){
                auto x=q.front();q.pop();
                int w=x.second;
                TreeNode*curr=x.first;
                s.insert({w,curr->val});
                // mp[w].push_back(curr->val);
                if(curr->left)q.push({curr->left,w-1});
                if(curr->right)q.push({curr->right,w+1});
            }
            for(auto i:s){
                mp[i.first].push_back(i.second);
            }
        }
        vector<vector<int>>ans;
        for(auto x:mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};