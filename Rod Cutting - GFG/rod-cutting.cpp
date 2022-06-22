// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  vector<vector<int>>t;
  int help(int price[],int l,int n){
      
      if(l==0 || n==0){
          return 0;
      }
      if(t[n][l]!=-1){
          return t[n][l];
      }
      if((n)<=l){
          return t[n][l]=( max((price[n-1]+help(price,l-(n),n)),(help(price,l,n-1))));
      }
      else{
          return t[n][l]=help(price,l,n-1);
      }
  }
    int cutRod(int price[], int n) {
        //code here
        t=vector<vector<int>>(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0){
                    t[i][j]=0;
                }
            }
        }
        return help(price,n,n);
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