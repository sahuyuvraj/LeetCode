class Solution {
public:
    bool kahnsAlgo(vector<int>adj[],int n,vector<int>&indegree,vector<int>&ans){
        queue<int>q;
        
        for(int i=0;i<n;++i){
            if(indegree[i]==0)
                q.push(i);
        }
        
        int count=0;
        while(!q.empty()){
            int curr=q.front();q.pop();
            
            for(auto it:adj[curr]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
            
            ans.push_back(curr);
            count++;
        }
        if(count!=n)return false;
        return true;
        
    }
    vector<int> findOrder(int nC, vector<vector<int>>& pre) {
        int n=pre.size();
        vector<int>adj[nC];
        vector<int>indegree(nC,0);
        
        for(int i=0;i<n;++i){
            adj[pre[i][1]].push_back(pre[i][0]);
            indegree[pre[i][0]]++;
        }
        
        vector<int>ans;
        if(kahnsAlgo(adj,nC,indegree,ans))
            return ans;
        return {};
        
    }
};