class Solution {
public:
    
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){return a[1]<b[1];});
        int count=0;
        vector<int>res=intervals[0];
        for(int i=1;i<intervals.size();i++)
            if(res[1]>intervals[i][0])count++;
            else res=intervals[i];
        return count;
    }
};