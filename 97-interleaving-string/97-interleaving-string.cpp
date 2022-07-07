class Solution {
public:
    int dp[101][101];
    bool solve(string s1,int n,string s2,int m,string s3,int len){
        if(len==0)return 1;
        if(dp[n][m]!=-1)return dp[n][m];
        
        int a=0,b=0;
        if(n-1>=0 and s1[n-1]==s3[len-1])a=solve(s1,n-1,s2,m,s3,len-1);
        if(m-1>=0 and s2[m-1]==s3[len-1])b=solve(s1,n,s2,m-1,s3,len-1);
        
        return dp[n][m]=a or b;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        
        int n=s1.size();
        int m=s2.size();
        int len=s3.size();
        if(n+m!=len)return false;
        dp[n][m];
        memset(dp,-1,sizeof(dp));
        return solve(s1,n,s2,m,s3,len);
    }
};