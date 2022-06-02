// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       //Your code here
       if(s1=="0" || s2=="0") return "0";
          int n = s1.size();
         int m  = s2.size();
         int f=0;
         
          if(s1[0]=='-'){
              f++;
              
              s1 = s1.substr(1,n-1);
          }
          
          if(s2[0]=='-'){
              f++;
              
              s2 = s2.substr(1,m-1);
          }
        
           n = s1.size();
           m  = s2.size();
         
         
         vector<int>v(n+m,0);
         
         
          for(int i=n-1;i>=0;i--){
              for(int j= m-1;j>=0;j--){
                  
                  
                  v[i+j+1] += (s1[i]-'0') *(s2[j]-'0');
                  v[i+j] += v[i+j+1]/10;
                  v[i+j+1]%=10;
              }
          }
        
        
         int i = 0;
         int c=0;
        string ans = "";
        while (v[i] == 0) i++;
       
        
        
          while (i < v.size()) ans += to_string(abs(v[i++]));
        
        if(f %2==1){
            ans = "-"+ans;
            return ans;
        }
        return ans;
    }

};

// { Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}  // } Driver Code Ends