// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

int maxProfit(vector<int>&price){
    //Write your code here..
    int n=price.size();
    int dp[n];
    dp[n-1]=0;
    int ma=price[n-1];
    for(int i=n-2;i>=0;i--){
        dp[i]= max(dp[i+1],ma-price[i]);
        if(ma<price[i])ma=price[i];
    }
    
    int mi=price[0];
    for(int i=1;i<n;i++){
        dp[i]=max(dp[i-1],dp[i]+price[i]-mi);
        if(mi>price[i])mi=price[i];
    }
    
    return dp[n-1];
}

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}
  // } Driver Code Ends