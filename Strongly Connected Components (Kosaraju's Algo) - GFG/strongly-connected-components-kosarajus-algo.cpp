// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
   
   void DFS2(int curr,vector<bool>&vis,vector<int>rev[]){
       vis[curr]=true;
       for(int j:rev[curr]){
           if(!vis[j])
           DFS2(j,vis,rev);
       }
   }
   
   void DFS1(int i,vector<bool>&visited,stack<int>&mystack,vector<int>adj[],int V){
    visited[i]=true;
    for(int j:adj[i])
      if(visited[j]==false)
          DFS1(j,visited,mystack,adj,V);
    mystack.push(i);
}

    void reverse(vector<int>adj[],vector<int>rev[],int V){
    for(int i=0;i<V;i++){
        for(int j:adj[i])
        rev[j].push_back(i);
    }
}
    
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
    stack<int>mystack;
    vector<bool>visited(V,false);
    vector<int>rev[V];
    for(int i=0;i<V;i++){
        if(!visited[i])
           DFS1(i,visited,mystack,adj,V);
    }
    
    reverse(adj,rev,V);

    for(int i=0;i<V;i++){
        visited[i]=false;
    }
    
    int cnt=0;
    while(!mystack.empty()){
        int curr=mystack.top();
        mystack.pop();
        if(!visited[curr]){
            cnt++;
            DFS2(curr,visited,rev);
        }
    }
    return cnt;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends