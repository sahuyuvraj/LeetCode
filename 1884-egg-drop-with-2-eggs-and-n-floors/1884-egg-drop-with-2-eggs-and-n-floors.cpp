class Solution {
public:
    int dp[3][1001];
    
    int memo(int e,int n){
        if(e==1 or n==0 or n==1)return n;
        if(dp[e][n]!=-1)return dp[e][n];
        int ans=INT_MAX;
        for(int i=1;i<=n;i++){
            int t=1+max(memo(e-1,i-1),memo(e,n-i));
            ans=min(ans,t);
        }
        return dp[e][n]=ans;
    }
    
    int twoEggDrop(int n) {
        memset(dp,-1,sizeof(dp));
        return memo(2,n);
    }
};