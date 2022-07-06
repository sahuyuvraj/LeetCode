// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int inSequence(int A, int B, int C){
        // code here
       if(C==0)return A==B;
        
        int n=(B-A)/C;
        if(n<0)return 0;
        if((B-A)%C==0)return 1;
        return 0;
    }
};

// A=2 B=10 C=15

// A=2 B=18 C=4
// A=-2 B=-9 C=7
// A=5 B=35 C=5
//  rem=0
//  dev=7
 
//  return (rem+A==C);

// 5 10 
// A=1 C=2 B=3
// 3 

// 10
// 15


// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}  // } Driver Code Ends