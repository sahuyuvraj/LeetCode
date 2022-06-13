class Solution {
public:
    int solve(vector<vector<int>>& t,int i,int j,int n,vector<vector<int>>&dp){
        
        if(i==n-1)return t[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
       
        return dp[i][j]=t[i][j]+min(solve(t,i+1,j,n,dp),solve(t,i+1,j+1,n,dp));
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(triangle,0,0,n,dp);
    }
}; 
// Memoization
	