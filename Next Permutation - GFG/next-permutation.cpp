// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        bool FLAG=false;
        int i;
        for(i=N-2;i>=0;i--){
            if(arr[i]<arr[i+1]){
                FLAG=true;
                break;
            }
        }
        
        if(!FLAG){
            reverse(arr.begin(),arr.end());
            return arr;
        }
        
        sort(arr.begin()+i+1,arr.end());
        int k=i+1;
        
        while(arr[i]>=arr[k]){
            k++;
        }
        
        swap(arr[i],arr[k]);
        return arr;
    }
};

// { Driver Code Starts.

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
}  // } Driver Code Ends