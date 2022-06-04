class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    unordered_map<char,int> map;
    
    int n = s.size();
    int j=0;
    int maxLength = 0;
    for(int i=0; i<n; i++) {
        map[s[i]]++;
        while(map[s[i]] >1) {
            map[s[j]]--;
            j++;
        }
        maxLength = max(maxLength,i-j+1);
    }
    return maxLength;
    }
};