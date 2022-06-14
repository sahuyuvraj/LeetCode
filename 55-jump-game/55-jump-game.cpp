class Solution {
public:
    bool canJump(vector<int>& nums) {
        int req_step=1,n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]>=req_step){
                req_step=1;
            }else{
                req_step++;
            }
        }
        return req_step==1?true:false;
    }
};