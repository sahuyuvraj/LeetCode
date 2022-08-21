class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row=obstacleGrid.size();
        int col=obstacleGrid[0].size();
        int dp[row][col];
        bool flg=false;
        
        //fill the row
        for(int i=0;i<col;i++){
            if(flg or obstacleGrid[0][i]){
                flg=true;
                dp[0][i]=0;
            }else{
                dp[0][i]=1;
            }
        }
        
        //fill the column
        flg=false;
        for(int i=0;i<row;i++){
            if(flg or obstacleGrid[i][0]){
                flg=true;
                dp[i][0]=0;
            }else{
                dp[i][0]=1;
            }
        }
        
        //fill the dp matrix
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if(obstacleGrid[i][j]){
                    dp[i][j]=0;
                }else{
                    dp[i][j]=dp[i][j-1]+dp[i-1][j];
                }
            }
        }
        return dp[row-1][col-1];
        
    }
};