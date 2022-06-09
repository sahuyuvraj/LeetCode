class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<mat.size();i++){
            int low=0,high=mat[0].size()-1,mid;
            while(low<=high){
                mid=low+(high-low)/2;
                if(mat[i][mid]==1)low=mid+1;
                else high=mid-1;
            }
            pq.push({low,i});
            if(pq.size()>k)pq.pop();
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};