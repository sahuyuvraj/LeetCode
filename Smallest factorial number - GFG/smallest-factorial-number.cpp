// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    bool check(int mid,int n){
        int cnt=0;
        
        while(mid){
     //cout<<mul<<" ";
            cnt+=mid/5;
            mid/=5;
        }
        return (cnt>=n);
    }
        int findNum(int n)
        {
        //complete the function here
       if(n==1)return 5;
       int low=1,high=n*5,mid;
       while(low<high){
           mid=low+(high-low)/2;
           if(check(mid,n))high=mid;
           else low=mid+1;
       }
       return low;
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends