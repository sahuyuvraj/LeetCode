// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        // code here
        int x=S/7;  //number of sundays                        1   1
        int y=S-x;  //total number of days we can purches      9   9
        int needed_food= S*M;   //                            20   300
        int days= needed_food/N; //                            1   15
        if(needed_food%N)days++;      //        extra days     1    0
        
        return days<=y?days:-1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}  // } Driver Code Ends