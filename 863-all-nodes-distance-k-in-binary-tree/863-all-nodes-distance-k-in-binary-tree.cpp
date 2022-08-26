/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    unordered_map<TreeNode*,TreeNode*>parent;
    
    void find_parent(TreeNode*root){
        if(!root)return;
        if(root->left)parent[root->left]=root;
        if(root->right)parent[root->right]=root;
        find_parent(root->left);
        find_parent(root->right);
    }
    
    void bfs(TreeNode*root,int k,queue<TreeNode*>&q){
        int cnt=0;
        unordered_map<TreeNode*,bool>vis;
        q.push(root);
        vis[root]=true;
        
        while(!q.empty()){
            if(cnt==k)break;
            cnt++;
            
            int n=q.size();
            for(int i=0;i<n;i++){
            TreeNode*curr=q.front();q.pop();
            
            if(curr->left and !vis[curr->left]){
                q.push(curr->left);
                vis[curr->left]=true;
            }
            if(curr->right and !vis[curr->right]){
                q.push(curr->right);
                vis[curr->right]=true;
            }
            if(parent[curr] and !vis[parent[curr]]){
                q.push(parent[curr]);
                vis[parent[curr]]=true;
            }
                
            }
        }
    }
    
    vector<int>solve(queue<TreeNode*>&q){
        vector<int>ans;
        while(!q.empty()){
            TreeNode*curr=q.front();q.pop();
            ans.push_back(curr->val);
        }
        return ans;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        parent.clear();
        find_parent(root);
        queue<TreeNode*>q;
        bfs(target,k,q);
        return solve(q);
    }
};

