class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        unordered_map<char,int>mp,mp2;
        for(char c:word1)mp[c]++;
        
        for(char c:word2){
            if(!mp[c])mp2[c]++;
            mp[c]--;
            if(mp[c]<-3 or mp2[c]>3)return false;
        }
        
        for(auto x:mp)if(x.second>3)return false;
        return true;
    }
};

