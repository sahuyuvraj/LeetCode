//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    
    bool check(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)return true;
            }
        }
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        int count=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)q.push({i,j});
            }
        }
        
        //delimiter
        q.push({-1,-1});
        
        while(!q.empty()){
            
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            if(i==-1 and j==-1 and q.empty())break;
            if(i==-1 and j==-1 and !q.empty()){
                count++;
                q.push({-1,-1});
                continue;
            }
            
            //upperside
            if(i-1>=0 and grid[i-1][j]==1){
                grid[i-1][j]=2;
                q.push({i-1,j});
            }
            //downside
            if(i+1<n and grid[i+1][j]==1){
                grid[i+1][j]=2;
                q.push({i+1,j});
            }
            //leftside
            if(j-1>=0 and grid[i][j-1]==1){
                grid[i][j-1]=2;
                q.push({i,j-1});
            }
            //rightside
            if(j+1<m and grid[i][j+1]==1){
                grid[i][j+1]=2;
                q.push({i,j+1});
            }

        }
        
        return check(grid)?-1:count;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends