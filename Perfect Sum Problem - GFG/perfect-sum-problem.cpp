// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	long long int  mod =1e9+7;
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        int dp[n+1][sum+1];
        for(int j=0;j<=sum;j++)dp[0][j]=0;
        for(int i=0;i<=n;i++)dp[i][0]=0;
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){   ////j=0 otherwise it will pass all test cases
               
//               Because , the array may contain 0 value ,
//               and if you run the loop from j = 1 ,

//               then it will get missed , 
//               so the loop should run from j = 0 
               
                if(arr[i-1]>j)dp[i][j]=(dp[i-1][j])%mod;
                else dp[i][j]=(dp[i-1][j])%mod+(dp[i-1][j-arr[i-1]])%mod;
            }
        }
        return (dp[n][sum])%mod;
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends