class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n=nums.size();
        
        if(k==0)return nums[0];
        
        if(k%2!=0 and n==1)return -1;
        
        //if(k==n)return -1;
        int val=0;
        for(int i=0;i<k-1 and i<n;i++){
            val=max(val,nums[i]);
        }
        int ans=0;
        if(k<n)ans=nums[k];
        return max(val,ans);
    }
};