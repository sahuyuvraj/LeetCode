//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
   void insert(stack<int>&St,int x){
       if(St.empty()){St.push(x);return;}
       int val=St.top();St.pop();
       insert(St,x);
       St.push(val);
   }
    void solve(stack<int>&St){
        if(St.empty())return;
        int x=St.top();
        St.pop();
        solve(St);
        insert(St,x);
    }
    
    stack<int> Reverse(stack<int> St){
        solve(St);
        return St;
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        stack<int> ans=ob.Reverse(St);
        vector<int>res;
        while(ans.size())
        {
            res.push_back(ans.top());
            ans.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends