class Solution {
public:
    int check(vector<int>&nums,int mid){
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=((nums[i]+mid-1)/mid)-1;
        }
        return ans;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1,high=INT_MAX-1,mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(check(nums,mid)<=maxOperations)high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};