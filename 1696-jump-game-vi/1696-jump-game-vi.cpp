class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int,int>>pq;
        pq.push({nums[n-1],n-1});
        
        int max_sum=nums[n-1];
        for(int i=n-2;i>=0;i--){
            while(!pq.empty() and pq.top().second-i>k)pq.pop();
            max_sum=pq.top().first+nums[i];
            pq.push({max_sum,i});
        }
        return max_sum;
    }
};