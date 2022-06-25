// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    vector<int>v;
        vector <int> search(string pat, string txt)
        {
            //code here.
            int t_size=txt.size();
            int p_size=pat.size();
            for(int i=0;i<t_size-p_size+1;i++){
                string sub=txt.substr(i,p_size);
                if(sub==pat)v.push_back(i+1);
            }
            if(v.empty())return {-1};
            return v;
        }
     
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends