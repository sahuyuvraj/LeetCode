class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size()!=t.size())return false;
        
        unordered_map<char,int>mp;
        
        for(char c:s)mp[c]++;
        
        for(char c:t)
            if(!mp[c])return false;
            else mp[c]--;
        return true;
    }
};