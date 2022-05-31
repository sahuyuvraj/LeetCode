class Solution {
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
    
    void dfs(int node,vector<int>adj[],vector<bool>&vis,stack<int>&st){
        vis[node]=true;
        for(int i=0;i<adj[node].size();i++){
            if(!vis[adj[node][i]]){
                dfs(adj[node][i],adj,vis,st);
            }
        }
        st.push(node);
    }
    
    vector<int> findOrder(int Courses, vector<vector<int>>& pre) {
        
        vector<int>adj[Courses];
        for(int i=0;i<pre.size();i++)
            adj[pre[i][1]].push_back(pre[i][0]);
        
        vector<int>ans;
        if(checkCycle(Courses,adj))return ans;
        stack<int>st;
        vector<bool>vis(Courses,false);
        for(int i=0;i<Courses;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
       // reverse(ans.begin(),ans.end());
        return ans;
    }
};