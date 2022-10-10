//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
        // code here
       stack<char>st;
       
       for(char c:s){
          if(c>='a' and c<='z')continue;
          else if(c=='(')st.push(c);
          else if(c==')'){
              if(st.top()=='(')return 1;
              while(st.top()!='(')st.pop();
              st.pop();
          }else st.push(c);
       }
       
       return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends