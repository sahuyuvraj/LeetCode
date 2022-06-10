class Solution {
public:
    bool canConstruct(string r, string m) {
        if(r.size()>m.size())return false;
        unordered_map<char,int>mp;
        for(char c:m)mp[c]++;
        for(char c:r)
            if(!mp[c])return false;
            else mp[c]--;
        return true;
    }
};