class Solution {
public:
    
    int check(vector<vector<int>>& grid) {
         for(int i=0;i<grid.size();i++){
             for(int j=0;j<grid[0].size();j++){
                 if(grid[i][j]==1)return true;
             }
         }
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        
        int r=grid.size();
        int c=grid[0].size();
        
        queue<pair<int,int>>q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        
        //delemeter
        q.push({-1,-1});
        int count=0;
        
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            
            if(i==-1 and j==-1 and q.empty())break;
            else if(i==-1 and j==-1){
                count++;
                q.push({-1,-1});
            }else{
                //upside
                if(i-1>=0 and grid[i-1][j]==1){
                    grid[i-1][j]=2;
                    q.push({i-1,j});
                }
                
                //downside
                if(i+1<r and grid[i+1][j]==1){
                    grid[i+1][j]=2;
                    q.push({i+1,j});
                }
                
              //leftside
                if(j-1>=0 and grid[i][j-1]==1){
                    grid[i][j-1]=2;
                    q.push({i,j-1});
                }
                
                //rightside
                if(j+1<c and grid[i][j+1]==1){
                    grid[i][j+1]=2;
                    q.push({i,j+1});
                }
            }
            
        }
        
        return check(grid)?-1:count;
    }
};