class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            int low=0,high=grid[0].size()-1,mid;
            while(low<=high){
                mid=low+(high-low)/2;
                if(grid[i][mid]<0)high=mid-1;
                else low=mid+1;
            }
            cnt+=grid[0].size()-low;
        }
        return cnt;
    }
};