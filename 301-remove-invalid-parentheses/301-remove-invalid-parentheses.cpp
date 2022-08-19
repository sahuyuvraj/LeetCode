class Solution {
public:
    
    int find_removals(string s){
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(st.size() and st.top()=='(' and s[i]==')')st.pop();
            else if(s[i]=='(' or s[i]==')')st.push(s[i]);
        }
        return st.size();
    }
    
    void solve(string s,vector<string>&ans,int min_removals,unordered_map<string,int>&mp){
        if(mp[s])return;
        mp[s]=1;
        if(min_removals==0){
            int min_remove=find_removals(s);
            if(min_remove==0){
                ans.push_back(s);
                return;
            }
        }else{
            for(int i=0;i<s.size();i++){
                string left=s.substr(0,i);
                string right=s.substr(i+1);
                string join=left+right;
                solve(join,ans,min_removals-1,mp);
            }
        }
    }
    
    
    vector<string> removeInvalidParentheses(string s) {
        vector<string>ans;
        unordered_map<string,int>mp;
        int min_removals=find_removals(s);
        
        solve(s,ans,min_removals,mp);
        return ans;
    }
};