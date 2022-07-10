// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        // code here
int i,j,max=0,curr=0;
       if(n==1)
       {
           return 0;
       }
       for(i=0;i<n;i++)
       {
           for(j=n-1;j>=i;j--)
           {
               if(arr[i]<=arr[j])
               {
                   curr = j-i;
                   break;
               }
           }
           if(curr>max)
           {
               max = curr;
           }
       }
       return max;
    }

};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends