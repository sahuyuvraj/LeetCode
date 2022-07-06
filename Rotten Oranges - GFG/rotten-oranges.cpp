// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:

    bool checkall(vector<vector<int>>&grid){
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)return true;
            }
        }
        return false;
    }
    
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        
        queue<pair<int,int>>q;
        int r=grid.size();
        int c=grid[0].size();
        
        //add all rotten oranges
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        
        int count=0;
        //delimiter (starting point of the new section)
        q.push({-1,-1});
        
        // check till queue is not empty
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            
            // chreck if the last section
            if(i==-1 and j==-1 and q.size()==1){
                q.pop();
                break;
                
            }else if(i==-1 and j==-1 and q.size()>1){
                q.pop();
                count++;
                q.push({-1,-1});
            
                
            }else{
                
                // check for upside 
                if((i-1)>=0 and grid[i-1][j]==1){
                    grid[i-1][j]=2;
                    q.push({i-1,j});
                }
                
                // check for downside 
                if((i+1)<r and grid[i+1][j]==1){
                    grid[i+1][j]=2;
                    q.push({i+1,j});
                }
                
                // check for leftside 
                if((j-1)>=0 and grid[i][j-1]==1){
                    grid[i][j-1]=2;
                    q.push({i,j-1});
                }
                
                // check for rightside 
                if((j+1)<c and grid[i][j+1]==1){
                    grid[i][j+1]=2;
                    q.push({i,j+1});
                }
                
                //pop the pair
                q.pop();
            }
        }
        
        return (checkall(grid))?-1:count;
        
    }
        
//     6 5
// 1 2 0 2 2
// 2 1 2 1 2
// 1 2 2 1 2
// 2 1 1 2 2
// 2 1 2 1 1
// 0 1 1 0 1

};

// { Driver Code Starts.
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
}  // } Driver Code Ends