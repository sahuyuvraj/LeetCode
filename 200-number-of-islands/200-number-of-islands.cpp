class Solution {
public:
    void bfs(int i,int j,vector<vector<char>>&grid,int row,int col){
        if(i<0 or i>=row or j<0 or j>=col or grid[i][j]!='1')return;
        grid[i][j]='2';
        bfs(i,j+1,grid,row,col);
        bfs(i+1,j,grid,row,col);
        bfs(i,j-1,grid,row,col);
        bfs(i-1,j,grid,row,col);
    }
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        if(row==0)return 0;
        int col=grid[0].size();
        int count=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'){
                    bfs(i,j,grid,row,col);
                    count++;
                }
            }
        }
        return count;
    }
};