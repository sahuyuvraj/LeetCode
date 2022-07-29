class Solution {
public:
    
    int dfs(vector<vector<int>>&grid,int i,int j){
        if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size() or grid[i][j]!=1)return 0;
        grid[i][j]=-1;
        
        int left=dfs(grid,i,j-1);
        int right=dfs(grid,i,j+1);
        int up=dfs(grid,i-1,j);
        int down=dfs(grid,i+1,j);
        return 1+up+down+left+right;
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area=0;
        int row=grid.size();
        int col=grid[0].size();
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    max_area=max(max_area,dfs(grid,i,j));
                }
            }
        }
        return max_area;
    }
};