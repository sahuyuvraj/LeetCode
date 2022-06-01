// { Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    string solve(string str, int status, int k){
       if(str=="" || status==0){
           return str;
       }
       string val="";
       int temp=0;
       int i=0;
       while(i<str.size()-1){
           if(str[i]==str[i+1]){
               int j = i+1;
               while(j<str.size() && str[j]==str[i] && j-i+1 != k){
                   j++;
               }
               if(str[j]==str[i] && j-i+1 == k){
                   temp=1;
                   i=j+1;
               }
               else{
                   val+= str[i];
                   i++;
               }
           }
           else{
               val+=str[i];
               i++;
           }
       }
       if(i==str.size()-1){
           val+= str[i];
       }
       return solve(val, temp, k);
   }
   
    string Reduced_String(int k,string s){
        // Your code goes here
       if(k==1)return "";
        return solve(s,1,k);
    }


};

// { Driver Code Starts.

int main() {
    
    
    int t;cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.Reduced_String(k,s)<<"\n";
        
    }
    
	return 0;
}  // } Driver Code Ends