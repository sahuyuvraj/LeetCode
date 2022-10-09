class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char,int>mp;
        for(char c:s)
            if(mp[c]==1)return c;
            else mp[c]++;
        
        return '-1';
    }
};