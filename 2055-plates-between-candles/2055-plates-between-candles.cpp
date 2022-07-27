class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int m=queries.size();
        vector<int>CanPos,ans(m,0);
        for(int i=0;i<s.size();i++) {
            if(s[i]=='|')CanPos.push_back(i);
        }
        for(int i=0;i<m;i++) {
            int l=lower_bound(CanPos.begin(),CanPos.end(),queries[i][0])-CanPos.begin();
            int r=upper_bound(CanPos.begin(),CanPos.end(),queries[i][1])-CanPos.begin()-1;
            if(l<r)ans[i]=(CanPos[r]-CanPos[l]-(r-l));
        }
        return ans;
    }
};