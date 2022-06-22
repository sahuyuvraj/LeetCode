// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
   int solve(vector<vector<int>>&memo,int price[],int len,int n){
       if(len==0 or n==0)return 0;
       if(memo[n][len]!=-1)return memo[n][len];
       if(n>len)return memo[n][len]=solve(memo,price,len,n-1);
       else return memo[n][len]=max(solve(memo,price,len,n-1),price[n-1]+solve(memo,price,len-n,n));
   }
  
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>memo(n+1,vector<int>(n+1,-1));
        for(int j=0;j<=n;j++)memo[0][j]=0;
        for(int i=0;i<=n;i++)memo[i][0]=0;
        return solve(memo,price,n,n);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends