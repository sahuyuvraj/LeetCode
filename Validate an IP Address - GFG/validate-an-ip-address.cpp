// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            // code here
           int i=0;
           int flag=0,sum=0;
           int cnt=0;
           while(s[i]!='\0')
           {
                if(s[i]=='.' && s[i+1]!='.' )
               {
                   cnt++;
                   if(sum<0 || sum>255)
                     return 0;
                    sum=0;
                    flag=0;
               }
               if(s[i]=='0'  && flag==0)
               {
                   if(s[i+1]>0 &&s[i+1]!='.')
                      return 0;
                   
               }
               if(s[i]!='.' && s[i]<=58)
               {
                   sum=sum*10+(s[i]-'0');
                   flag=1;
               }
               else if(s[i]>=97 && s[i]<=122)
               {
                   return 0;
               }                  
               i++;
           }
           if(cnt!=3)
           {
               return 0;
           }
           return 1;
        }
};

// { Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}  // } Driver Code Ends