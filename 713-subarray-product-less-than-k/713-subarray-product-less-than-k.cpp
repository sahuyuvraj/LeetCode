class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int sum=1,cnt=0;
        int i=0,j=0;
        while(i<nums.size() and j<nums.size()){
            if(sum*nums[j]<k){
                cnt+=(j-i+1);
                sum*=nums[j];
                j++;
            }else{
                sum/=nums[i++];
                if(i>j)j=i;
                if(sum==0)sum=1;
            }
        }
        return cnt;
    }
};