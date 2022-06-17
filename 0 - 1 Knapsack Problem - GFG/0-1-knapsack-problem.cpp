// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int memo(vector<vector<int>>&dp,int W, int wt[], int val[], int n){
       if(W==0 or n==0)return 0;
       if(dp[W][n]!=-1)return dp[W][n];
       if(wt[n-1]>W)dp[W][n]=memo(dp,W,wt,val,n-1);
       else return dp[W][n]= max(memo(dp,W,wt,val,n-1),val[n-1]+memo(dp,W-wt[n-1],wt,val,n-1));
    
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
    vector<vector<int>>dp(W+1,vector<int>(n+1,-1));
    return memo(dp,W,wt,val,n);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends