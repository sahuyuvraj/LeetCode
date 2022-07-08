// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int n, vector<vector<int>>m) {
        // code here
      priority_queue<int, vector<int>, greater<int>>q;
       for(int i=0; i<n; ++i){
           
           for(int j=0; j<n; ++j){
               
               q.push(m[i][j]);
           }
       }
        for(int i=0; i<n; ++i){
           
           for(int j=0; j<n; ++j){
               
               m[i][j]=q.top();
               q.pop();
               
           }
       }
       return m;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> v[i][j];
        Solution ob;
        v = ob.sortedMatrix(N, v);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << v[i][j] << " ";
            cout << "\n";
        }
    }
}  // } Driver Code Ends