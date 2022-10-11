//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        int flg=0,ind=N-1;
        for(int i=N-2;i>=0;i--){
            if(arr[i+1]>arr[i]){
                flg=1;
                ind=i;
                break;
            }
        }
        
        if(flg==0){
            reverse(arr.begin(),arr.end());
            return arr;
        }
        
        sort(arr.begin()+ind+1,arr.end());
        
        for(int k=ind+1;k<N;k++){
            if(arr[k]>arr[ind]){
                swap(arr[k],arr[ind]);
                break;
            }
        }
        return arr;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends