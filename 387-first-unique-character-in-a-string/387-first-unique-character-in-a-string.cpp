class Solution {
public:
    int firstUniqChar(string s) {
        for(int i=0;i<s.size();i++){
            if(s.find_first_of(s[i])==i and s.find_last_of(s[i])==i)return i;
        }
        return -1;
    }
};