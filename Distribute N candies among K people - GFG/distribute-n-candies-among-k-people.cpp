// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<long long> distributeCandies(int N, int K) {
        // code here
        vector<long long >ans(K,0);
        int j=0;
        while(N>0){
            for(int i=0;i<K;i++){
                j++;
                N-=j;
                if(N<=0){
                    ans[i]+=N+j;
                    break;
                }else{
                    ans[i]+=j;
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N>>K;
        
        Solution ob;
        vector<long long> res = ob.distributeCandies(N,K);
        
        for(int i=0; i<res.size(); i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends