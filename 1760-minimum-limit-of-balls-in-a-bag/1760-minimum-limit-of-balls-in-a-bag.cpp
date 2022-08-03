class Solution {
public:
    
    bool check(vector<int>&nums,int mid,int maxOp){
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=(nums[i]-1)/mid;
            if(ans>maxOp)return false;
        }
        return true;
    }
    
    int minimumSize(vector<int>& nums, int maxOp) {

        int low=1,high=*max_element(nums.begin(),nums.end());
        int mid,ans=0;
        while(low<=high){
            mid=low+(high-low)/2;
            if(check(nums,mid,maxOp))ans=mid,high=mid-1;
            else low=mid+1;
        }
        return ans;
    }
};