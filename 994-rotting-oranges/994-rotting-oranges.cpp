class Solution {
public:
    
    bool checkall(vector<vector<int>>&grid){
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
        
        int count=0;
        //delimiter
        q.push({-1,-1});
        
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            
            if(i==-1 and j==-1 and !q.size()){
                break;
            }else if(i==-1 and j==-1){
                count++;
                q.push({-1,-1});
            }else{
                
                //check upside
                if((i-1)>=0 and grid[i-1][j]==1){
                    grid[i-1][j]=2;
                    q.push({i-1,j});
                }
                //check downside
                if((i+1)<r and grid[i+1][j]==1){
                    grid[i+1][j]=2;
                    q.push({i+1,j});
                }
                
                 //check upside
                if((j-1)>=0 and grid[i][j-1]==1){
                    grid[i][j-1]=2;
                    q.push({i,j-1});
                }
                //check upside
                if((j+1)<c and grid[i][j+1]==1){
                    grid[i][j+1]=2;
                    q.push({i,j+1});
                }
            }
        }
        return checkall(grid)?-1:count;
    }
};