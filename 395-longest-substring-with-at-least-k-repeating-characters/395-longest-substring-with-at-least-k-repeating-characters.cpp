class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.size(),ind=0;
        
        unordered_map<char,int>mp;
        
        for(char c:s)mp[c]++;
        
        while(ind<n and mp[s[ind]]>=k)++ind;
        
        if(ind==n)return n;
        
       int left=longestSubstring(s.substr(0,ind),k);
        
        while(ind<n and mp[s[ind]]<k)++ind;
        
        int right=longestSubstring(s.substr(ind),k);
        
        return max(left,right);
        
    }
};