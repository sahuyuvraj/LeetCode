class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int>s;
        
        int curr_sum=0,prev_sum=0;
        
        for(int i=0;i<nums.size();i++){
            
            curr_sum+=nums[i];
            
            if(s.find(curr_sum%k)!=s.end())return true;
            
            s.insert(prev_sum%k);
            prev_sum=curr_sum;
        }
        return false;
    }
};