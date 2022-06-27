// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:

    // string sum(string s1,string s2){
    //     int n1=s1.size();
    //     int n2=s2.size();
        
    // }
    
    
    string solve(int arr[], int n) {
        // code here
        
        sort(arr,arr+n);
        // string s1="";
        // string s2="";
        string ans="";
         int end=n-1;
         int c=0;
         while(end>=0){

          int sum=0;
          sum+=arr[end--];
          if(end>=0)sum+=arr[end--];
          if(c!=0)sum+=c;
          ans+=to_string(sum%10);
          c=sum/10;
         }
         if(c!=0)ans+=to_string(c);
        reverse(ans.begin(),ans.end());
        int i=0;
        while(ans[i]=='0')i++;
        //string ans=sum(s1,s2);
        
        return ans.substr(i);
        
        
        
// N = 6
// Arr[] = {6, 8, 4, 5, 2, 3}
//          2, 3, 4, 5, 6 ,8
//          2     4     6
//           3      5     8
           
           
// Output: 604
// Explanation: The minimum sum is formed 
// by numbers 358 and 246.

// N = 5
// Arr[] = {5, 3, 0, 7, 4}
//          0, 3, 4, 5, 7
//          0    4     7
//           3     5
           
// Output: 82
// Explanation: The minimum sum is 
// formed by numbers 35 and 047.
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends