class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1)return false;
        sum/=2;
        int n=nums.size();
        bool dp[n+1][sum+1];
        
        for(int i=0;i<=n;i++)
        for(int j=0;j<=sum;j++){
                if(i==0)dp[i][j]=false;
                if(j==0)dp[i][j]=true;
        }
            
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(nums[i-1]>j)dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i-1][j] or dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][sum];
        

    }
};