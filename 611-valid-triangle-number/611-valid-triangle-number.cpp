class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n<3)return 0;
        int cnt=0;
        for(int i=n-1;i>=0;i--){
            
            int low=0,high=i-1;
            
            while(low<high){
                if(nums[low]+nums[high]>nums[i]){
                    cnt+=(high-low);
                    high--;
                }else low++;
            }
        }
       return cnt; 
    }
};