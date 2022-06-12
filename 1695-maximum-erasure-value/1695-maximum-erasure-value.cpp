class Solution {
public:
    int max_sum=0;
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int>mp;
        int j=0,sum=0;
        
        for(int i=0;i<nums.size();i++){
            if(!mp[nums[i]]){
                mp[nums[i]]++;
                sum+=nums[i];
                max_sum=max(max_sum,sum);
            }else{
                while(nums[j]!=nums[i]){
                int x=nums[j++];
                mp[x]--;
                sum-=x;                    
                }
                int x=nums[j++];
                mp[x]--;
                sum-=x;

                mp[nums[i]]++;
                sum+=nums[i];
                max_sum=max(max_sum,sum);
            }
        }
        return max_sum;
    }
};