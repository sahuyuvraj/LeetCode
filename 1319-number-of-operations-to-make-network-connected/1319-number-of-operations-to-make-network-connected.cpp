class Solution {
public:
    void dfs(vector<vector<int>>&g,vector<bool>&vis,int node){
        vis[node]=true;
        for(int i=0;i<g[node].size();i++){
            if(!vis[g[node][i]]){
                dfs(g,vis,g[node][i]);
            }
        }
    }
    int connect(vector<vector<int>>&g,int n){
        int ans=0;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(g,vis,i);
                ans++;
            }
        }
        return ans;
    }
    int makeConnected(int n, vector<vector<int>>& con) {
        int v=con.size();
        if(v<n-1)return -1;
        vector<vector<int>>g(n);
        for(int i=0;i<v;i++){
            g[con[i][0]].push_back(con[i][1]);
            g[con[i][1]].push_back(con[i][0]);
        }
        return connect(g,n)-1;
    }
};