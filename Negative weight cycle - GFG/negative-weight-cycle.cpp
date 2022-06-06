// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
struct edge{
  int src;
  int dst;
  int wt;
};


int bellmanFord(vector<edge>&Edges,int V,int E){
    int parent[V];
    int cost_parent[V];
    vector<int>value(V,INT_MAX);

    //starting point
    parent[0]=-1;
    value[0]=0;  //start node has value=0 to get picked pick

    bool updated;

    for(int i=0;i<V-1;i++){
        updated=false;
        for(int j=0;j<E;j++){
            
            int U=Edges[j].src;
            int V=Edges[j].dst;
            int wt=Edges[j].wt;

            if(value[U]!=INT_MAX and value[U]+wt<value[V]){
                value[V]=value[U]+wt;
                parent[V]=U;
                cost_parent[V]=value[V];
                updated=true;
            }
        }
        if(updated==false)break;
    }

    //now check by relaxing onc3e more if e have a negative edge cycle

    for(int j=0;j<E and updated==true;j++){
        int U=Edges[j].src;
        int V=Edges[j].dst;
        int wt=Edges[j].wt;

        if(value[U]!=INT_MAX and value[U]+wt<value[V]){
        //    cout<<"Graph had -ve edge cycle\n";
            return 1;
        }

    }

    //printing sortest path
    return 0;

}


	int isNegativeWeightCycle(int V, vector<vector<int>>edges){
	    // Code here
	    int E=edges.size();
	    
	    vector<edge>Edges(E);
	    
	    for(int i=0;i<E;i++){
	    Edges[i].src=edges[i][0];    
	    Edges[i].dst=edges[i][1];    
	    Edges[i].wt=edges[i][2];    
	    }
	    
	    return bellmanFord(Edges,V,E);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends