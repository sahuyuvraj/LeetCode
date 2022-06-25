class Solution {
public:
    bool isInc(vector<int>&nums){
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i])return false;
        }
        return true;
    }
    bool checkPossibility(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                int x=nums[i-1],y=nums[i];
                nums[i-1]=y;
                if(isInc(nums))return true;
                else{
                    nums[i]=x;
                    nums[i-1]=x;
                    return isInc(nums);
                }
            }
        }
        return true;
    }
};