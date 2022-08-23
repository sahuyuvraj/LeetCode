class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int mul=1;
        
        for(int i=0;i<nums.size();i++){
            mul*=nums[i];
            ans=max(max(nums[i],mul),ans);
            if(mul==0){
                mul=1;
                continue;
            }
        }
        mul=1;
       for(int i=nums.size()-1;i>=0;i--){
            mul*=nums[i];
            ans=max(max(nums[i],mul),ans);
            if(mul==0){
                mul=1;
                continue;
            }
        }
        return ans;
    }
};