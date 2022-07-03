class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int mod=1000000007;
        vector dp(n,0);
        dp[0]=1;
        
        for(int i=0;i<n;i++){
            if(dp[i]==0)continue;
                for(int j=i+delay;j<min(i+forget,n);j++){
                    dp[j]+=dp[i];
                    dp[j]%=mod;
                }
        }
       int ans=0;
        for(int i=max(n-forget,0);i<n;i++)ans=(ans+dp[i])%mod;
        return ans;
    }
};