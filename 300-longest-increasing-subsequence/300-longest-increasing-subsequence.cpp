class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>dp(n,1);
        int total_max=1;
        
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]){
                    sum=max(sum,dp[j]);
                }
            }
            dp[i]+=sum;
            total_max=max(total_max,dp[i]);
        }
        return total_max;
    }
};