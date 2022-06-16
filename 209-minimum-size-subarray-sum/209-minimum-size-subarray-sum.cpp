class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum<target)return 0;
        if(sum==target)return nums.size();
        
        int i=0,j=0,ans=INT_MAX;
        sum=0;
        
        while(j<nums.size())
            if(sum+nums[j]<target)sum+=nums[j++];
            else ans=min(ans,j-i+1),sum-=nums[i++];
        
        return ans;
    }
};
