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
    
    unordered_map<TreeNode*,TreeNode*>parent;
    
    void find_parent(TreeNode*root){
        if(!root)return;
        if(root->left)parent[root->left]=root;
        if(root->right)parent[root->right]=root;
        find_parent(root->left);
        find_parent(root->right);
    }
    
    int bfs(TreeNode*root,queue<TreeNode*>&q){
        unordered_map<TreeNode*,bool>vis;
        q.push(root);
        vis[root]=true;
        int k=0;
        while(!q.empty()){
            k++;
            
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
        return k-1;
    }
    
    
    int distanceK(TreeNode* root, TreeNode* target) {
        parent.clear();
        find_parent(root);
        queue<TreeNode*>q;
        return  bfs(target,q);
    }
    
    TreeNode*find_Node(TreeNode*root,int target){
        if(!root)return NULL;
        if(root->val==target)return root;
        
        TreeNode*l=find_Node(root->left,target);
        if(l)return l;
        return find_Node(root->right,target);
    }
    
    int amountOfTime(TreeNode* root, int start) {
        TreeNode*target=find_Node(root,start);
       return distanceK(root,target); 
    }
};