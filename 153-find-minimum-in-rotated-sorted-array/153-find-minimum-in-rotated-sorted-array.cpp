class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int n = nums.size();
        if(n == 1 || (nums[0]<=nums[1] && nums[0]<=nums[n-1]))
            return nums[0];
        int l = 0, r = n;
        while(l<r)
        {
            int mid = l+(r-l)/2;
            if(nums[mid]<nums[0]) r = mid;
            else l = mid+1;
        }
        return nums[l];
    }
};       