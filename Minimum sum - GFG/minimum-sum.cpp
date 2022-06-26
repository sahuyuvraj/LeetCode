// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
      
      string sumstr(string s1,string s2){
          int n1=s1.size(),n2=s2.size();
          int i=n1-1;
          int j=n2-1;
          
          string ans="";
          
          int c=0;
          
          while(i>=0 or j>=0 or c){
              
              int sum=0;
              if(i>=0)sum+=s1[i--]-'0';
              if(j>=0)sum+=s2[j--]-'0';
              if(c)sum+=c;
              ans+=to_string(sum%10);
              c=sum/10;
          }
          reverse(ans.begin(),ans.end());
          i=0;
          while(ans[i]=='0')i++;
          return ans.substr(i);
      }
       
    string solve(int arr[], int n) {
        // code here
        sort(arr,arr+n);
        string s1="",s2="";
        for(int i=0;i<n;i++){
            s1+=to_string(arr[i++]);
            if(i<n)s2+=to_string(arr[i]);
        }
        //cout<<s1<<endl<<s2<<endl;
        string sum=sumstr(s1,s2);
        return sum;
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