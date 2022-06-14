// { Driver Code Starts
// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int *, int);

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, i;
        cin >> n;
        int price[n];
        for (i = 0; i < n; i++) cin >> price[i];
        // function call
        stockBuySell(price, n);
    }
    return 0;
}
// } Driver Code Ends


// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n) {
    // code here
    int i=0;
    while(i+1<n and price[i]>price[i+1])i++;
    
    if(i==n-1){cout<<"No Profit\n";return;}
    
    while(i<n){
        int j=i;
        while(i+1<n and price[i]<price[i+1])i++;
        if(i!=j)cout<<"("<<j<<" "<<i<<") ";
        i++;
    }
    cout<<"\n";
}