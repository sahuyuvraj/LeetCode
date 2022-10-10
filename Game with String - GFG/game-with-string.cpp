//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        unordered_map<char,int>mp;
        priority_queue<int>q;
        for(char c:s)mp[c]++;
        for(auto x:mp)q.push(x.second);
        
        for(int i=0;i<k;i++){
            int temp=q.top();
            q.pop();
            q.push(temp-1);
        }
        
        int ans=0;
        while(!q.empty()){
            ans+=pow(q.top(),2);q.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends