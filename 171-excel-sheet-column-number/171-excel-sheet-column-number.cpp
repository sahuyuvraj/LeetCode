class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans,n=columnTitle.size(),res=0;
        for(auto i:columnTitle)
            ans=26*res+(i-'A'+1),res=ans;
        return ans;
    }
};
