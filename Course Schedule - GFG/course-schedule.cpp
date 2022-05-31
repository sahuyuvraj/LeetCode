// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    bool check(int node,vector<bool>&vis,vector<bool>&difVis,vector<int>adj[]){
        vis[node]=true;
        difVis[node]=true;
        for(int i=0;i<adj[node].size();i++){
            if(!vis[adj[node][i]]){
                if(check(adj[node][i],vis,difVis,adj))return true;
            }else if(difVis[adj[node][i]])return true;
        }
        difVis[node]=false;
        return false;
    }
    bool checkCycle(int Courses,vector<int>adj[]){
        vector<bool>vis(Courses,false),difVis(Courses,false);
        for(int i=0;i<Courses;i++){
            if(!vis[i]){
                if(check(i,vis,difVis,adj))return true;
            }
        }
        return false;
    }
    
    void dfs(int node,vector<bool>&vis,vector<int>graph[],stack<int>&st){
          vis[node]=true;
          for(int i=0;i<graph[node].size();i++){
              if(!vis[graph[node][i]]){
                  dfs(graph[node][i],vis,graph,st);
              }
          }
          st.push(node);
    }
    vector<int> findOrder(int n, int m, vector<vector<int>> pre) 
    {
        //code here
        //vector<vector<int>>graph(n);
        vector<int>adj[n];
        
        // for(int i=0;i<m;i++)
        //   graph[pre[i][1]].push_back(pre[i][0]);
        for(int i=0;i<m;i++)
          adj[pre[i][1]].push_back(pre[i][0]);
        
        vector<int>ans;
        
        if(checkCycle(n,adj))return {};
        
        stack<int>st;
        vector<bool>vis(n,false);
    
        for(int i=0;i<n;i++)
            if(!vis[i])
                dfs(i,vis,adj,st);
    
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

// { Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends