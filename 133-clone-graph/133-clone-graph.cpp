/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
//     void dfs(Node*curr,Node*node,vector<Node*>&vis){
//         vis[curr->val]=node;
        
//         for(auto ele:curr->neighbors){
//             if(!vis[ele->val]){
//                 Node*newnode=new Node(ele->val);
//                 (node->neighbors).push_back(newnode);
//                 dfs(ele,newnode,vis);
//             }else{
//                 (node->neighbors).push_back(vis[ele->val]);
//             }
//         }
//     }
    
//     Node* cloneGraph(Node* node) {
//         if(node==NULL)return NULL;
        
//         vector<Node*>vis(1000,NULL);
//         Node*copy=new Node(node->val);
//         vis[node->val]=copy;
        
//         for(auto curr:node->neighbors){
//             if(!vis[curr->val]){
//                 Node*newnode=new Node(curr->val);
//                 (copy->neighbors).push_back(newnode);
//                 dfs(curr,newnode,vis);
//             }else{
//                 (copy->neighbors).push_back(vis[curr->val]);
//             }
//         }
//         return copy;
//     }
    
    unordered_map<Node*,Node*> m;
	Node* cloneGraph(Node* node) {
		if(!node) return NULL;
		if(m.count(node)!=0) return m[node];
		Node* copy_node = new Node(node->val);
		m[node]=copy_node;
		for(auto c:node->neighbors)
			m[node]->neighbors.push_back(cloneGraph(c));
		return m[node];
	}
};