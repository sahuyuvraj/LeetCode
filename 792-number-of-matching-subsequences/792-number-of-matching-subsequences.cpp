class Solution {
public:
    bool check(string s,string t){
        int u=0;int j=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==t[j])j++;
            if(j==t.size())return true;
        }
        if(j==t.size())return true;
        else return false;
    }
    int numMatchingSubseq(string s, vector<string>& word) {
        int count=0;
        unordered_map<string,int>mp;
        for(int i=0;i<word.size();i++)mp[word[i]]++;
        for(auto i=mp.begin();i!=mp.end();i++) if(check(s,i->first))count+=i->second;
        return count;
    }
};