class Solution {
public:
    int solve(vector<int>&nums,int s,int e){
        int prev=0,curr=nums[s];
        for(int i=s+1;i<=e;i++){
            int x=curr;
            curr=max(prev+nums[i],curr);
            prev=x;
        }
        return curr;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
       // if(n==2)return 0;
        return max(solve(nums,0,n-2),solve(nums,1,n-1));
    }
};