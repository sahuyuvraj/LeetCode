class Solution {
public:
    vector<vector<int>>ans;
    void dfs(vector<vector<int>>&graph,int node,vector<int>v,int n){
        
        v.push_back(node);
        
        if(node==n-1){ans.push_back(v);return;}
        
        for(auto i:graph[node])dfs(graph,i,v,n);
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        dfs(graph,0,{},n);
        return ans;
    }
};