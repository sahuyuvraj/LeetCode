class Solution {
public:
    bool is(string s){
        int i=0,j=s.size()-1; bool ans=true;
        while(i<j)
            if(s[i]==s[j]) {i++; j--;}
            else { ans=false; break;}
        return ans;
    }
    
    vector<vector<string>> partition(string s) {
        unordered_map<int, vector<vector<string>>> dp;
        int n=s.size();
        vector<string> v;
        v.push_back(s.substr(0,1));
        dp[0].push_back(v); v.pop_back();
        for(int i=1;i<n;i++)
        {
            for(int j=i;j>=0;j--)
            {
               string x=s.substr(j,i-j+1);
            if(is(x) and j) {
                vector<vector<string>> ans=dp[j-1];
               for(int k=0;k<ans.size();k++)
               { ans[k].push_back(x); dp[i].push_back(ans[k]); } }
                else if(is(x) and  !j) 
                {
                  v.push_back(x); dp[i].push_back(v); v.pop_back();  
                }
            }
        }

        return dp[n-1];
    }
};