class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // for(int i=0;i<nums.size();i++){
        //     if(nums[abs(nums[i])]>=0){
        //         nums[abs(nums[i])]= -nums[abs(nums[i])];
        //     }else return abs(nums[i]);
        // }
        // return -1;
        
        int slow=nums[0];
        int fast=nums[0];
        
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        
        fast=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};