class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int sum=accumulate(stones.begin(),stones.end(),0);
        
        bool dp[n+1][sum+1];
        for(int j=0;j<=sum;j++)dp[0][j]=false;
        for(int i=0;i<=n;i++)dp[i][0]=true;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(stones[i-1]>j)dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i-1][j] or dp[i-1][j-stones[i-1]];
            }
        }
        int min_diff=INT_MAX;
        for(int i=0;i<=sum/2;i++){
            if(dp[n][i] and sum-i*2<min_diff)min_diff=sum-i*2;
        }
        return min_diff;
    }
};