class Solution {
public:
    int firstUniqChar(string s) {
   for(int i = 0; i < s.length(); i++){
        if(s.find_last_of(s[i]) == i && s.find(s[i]) == i) return i;
    }
    return -1;
    }
};