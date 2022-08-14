class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        vector<int>dp(n + 1);
        
        dp[0]=0;
        dp[1]=0;
        
        for (int num=2;num<=n;num++) {
            if(num&1){
                for(int j=num/2;j>=1;j--){
                    if(num % j == 0){
                        dp[num]=dp[j]+num/j;
                        break;
                    }
                }
            } else {
                dp[num] = dp[num/2]+2;
            }
        }
        return dp[n];
    }
};

