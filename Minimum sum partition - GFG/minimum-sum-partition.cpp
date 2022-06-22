// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int stones[], int n)  { 
	    // Your code goes here
        int sum=accumulate(stones,stones+n,0);
        
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


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends