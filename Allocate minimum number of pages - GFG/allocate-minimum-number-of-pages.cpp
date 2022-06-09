// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool check(int A[],int mid,int M,int N){
        int student=1,res=0;
        for(int i=0;i<N;i++)
            if(res+A[i]<=mid)res+=A[i];
            else if(mid<A[i])return false;
            else res=A[i],student++;
        return student<=M;
    }
    
    int findPages(int A[], int N, int M) 
    {
        //code here
        int low=A[0];
        int high=accumulate(A,A+N,0);
        int res=-1,mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(check(A,mid,M,N))res=mid,high=mid-1;
            else low=mid+1;
        }    
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends