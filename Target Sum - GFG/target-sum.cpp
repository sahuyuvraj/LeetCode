// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int findTargetSumWays(vector<int>&nums ,int target) {
        //Your code here
        int n=nums.size();
        int total_sum=accumulate(nums.begin(),nums.end(),0);
        target=abs(target);
        if((total_sum+target)&1)return 0;
        int sum=(total_sum+target)/2;
        int dp[n+1][sum+1];
        for(int j=0;j<=sum;j++)dp[0][j]=0;
        for(int i=0;i<=n;i++)dp[i][0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(nums[i-1]>j)dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][sum];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends