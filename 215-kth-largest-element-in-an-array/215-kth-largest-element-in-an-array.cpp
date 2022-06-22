class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(int i:nums)pq.push(i);
        while(!pq.empty() and --k){
            pq.pop();
        }
        if(k<0)return -1;
        return pq.top();
    }
};