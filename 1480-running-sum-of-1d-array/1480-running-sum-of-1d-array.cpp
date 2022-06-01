class Solution {
public:
    vector<int>ans;
    int sum=0;
    void recursion(vector<int>&nums,int n,int i){
        if(i==n)return;
        sum+=nums[i++];
        ans.push_back(sum);
        recursion(nums,n,i);
    }
    vector<int> runningSum(vector<int>& nums) {
     
        // for(int i=1;i<nums.size();i++)
        //     nums[i]=nums[i]+nums[i-1];
        // return nums;
        
       recursion(nums,nums.size(),0);
        return ans;
    }
};
