class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>dq;
        int s=0;
        
        for(int i=0;i<nums.size();i++){
            
            while(!dq.empty() and dq.back()<nums[i])dq.pop_back();
            
            dq.push_back(nums[i]);
            
            if(i+1>=k){
                ans.push_back(dq.front());
                if(nums[s]==dq.front())dq.pop_front();
                s++;
            }
            
        }
        return ans;
    }
};