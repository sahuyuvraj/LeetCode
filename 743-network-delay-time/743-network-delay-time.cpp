class Solution {
    
    struct node{
      int dst;
        int wt;
    };
    
    struct qnode{
      int vertex;
        int dst;
    };
    
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        unordered_map<int,vector<node*>>adj;
        
        for(int i=0;i<times.size();i++){
            node*newnode=new node;
            newnode->dst=times[i][1];
            newnode->wt=times[i][2];
            adj[times[i][0]].push_back(newnode);
        }
        
        qnode *qn=new qnode;
        qn->vertex=k;
        qn->dst=0;
        queue<qnode*>q;
        q.push(qn);
        
        vector<int>distance(n+1,INT_MAX);
        distance[k]=0;
        int time=0;
        
        while(!q.empty()){
            
            qnode*curr=q.front();
            q.pop();
            
            for(auto it:adj[curr->vertex]){
               
                qnode*temp_qn=new qnode;
                temp_qn->vertex=it->dst;
                temp_qn->dst=it->wt+curr->dst;
                if(distance[temp_qn->vertex]>temp_qn->dst){
                    q.push(temp_qn);
                    distance[temp_qn->vertex]=it->wt+curr->dst;
                }
            }
        }
        
        //find the max distance
        for(int i=1;i<=n;i++){
            if(distance[i]==INT_MAX)return -1;
            time=max(time,distance[i]);
        }
        return time;
    }
};