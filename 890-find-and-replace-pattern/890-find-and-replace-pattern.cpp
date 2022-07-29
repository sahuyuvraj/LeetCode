class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
       
        for(string s:words){
        unordered_map<char,char>mp1,mp2;
            int flg=0;
            if(s.size()!=pattern.size())continue;
            for(int i=0;i<s.size();i++){
                if(!mp1[s[i]] and !mp2[pattern[i]]){
                    mp1[s[i]]=pattern[i];
                    mp2[pattern[i]]=s[i];
                }else if((mp2[pattern[i]] and mp2[pattern[i]]!=s[i])or(mp1[s[i]] and mp1[s[i]]!=pattern[i])){
                    flg=1;
                    break;
                }
            }
            if(!flg)ans.push_back(s);
        }
        return ans;
    }
};