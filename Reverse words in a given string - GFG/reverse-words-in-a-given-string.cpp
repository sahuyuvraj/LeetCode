// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        string ans="";
        replace(S.begin(),S.end(),'.',' ');
        stringstream ss(S);
        string buff;
        while(ss>>buff){
            reverse(buff.begin(),buff.end());
            ans+=buff;
            ans+='.';
        }
        reverse(ans.begin(),ans.end());
        return ans.substr(1);
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends