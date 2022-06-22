// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int dp[10005];
    
    int solve(int n,int x,int y,int z){
        if(n==0)return 0;
        if(dp[n]!=-1)return dp[n];
        
        int x_cut=INT_MIN,y_cut=INT_MIN,z_cut=INT_MIN;
        
        if(n>=x) x_cut=solve(n-x,x,y,z);
        if(n>=y) y_cut=solve(n-y,x,y,z);
        if(n>=z) z_cut=solve(n-z,x,y,z);
        return dp[n]=1+max(x_cut,max(y_cut,z_cut));
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        memset(dp,-1,sizeof(dp));
        int a=solve(n,x,y,z);
        return a<0?0:a;
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends