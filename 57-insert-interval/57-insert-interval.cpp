class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        vector<int>curr=intervals[0];
        for(auto it:intervals){
            if(curr[1]<it[0]){
                ans.push_back(curr);
                curr=it;
            }else{
                curr[1]=max(curr[1],it[1]);
            }
        }
        ans.push_back(curr);
        return ans;
    }
};