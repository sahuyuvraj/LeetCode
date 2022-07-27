class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        int l=0,h=n-1,mid;
        while(l<h){
            mid=l+(h-l)/2;
            if(mid>0 and mid<n-1){
                if(nums[mid]>nums[mid+1] and nums[mid]>nums[mid-1])return mid;
                else if(nums[mid]<nums[mid+1])l=mid+1;
                else h=mid-1;
            }else if(mid==0){
                return nums[0]<nums[1];
            }else if(mid==n-1){
                return nums[n-2]<nums[n-1];
            }
            
        }
        return h;
    }
};