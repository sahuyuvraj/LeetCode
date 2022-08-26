class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        unordered_map<char,int>sk;
        for(auto i:word1){sk[i]++;}
        for(auto i:word2){sk[i]--;}
        for(auto i:sk){if(i.second>3 or i.second<-3){return false;}}
        return true;
    }
};

