class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char>mp2;
        string ans="";
        int i=0;
        
        for(char c:key)
           if(c!=' ' and !mp2.count(c))mp2[c]=(i++)+'a';    
        
        mp2[' ']=' ';
        for(char c:message)ans.push_back(mp2[c]);
        return ans;
        
    }
};