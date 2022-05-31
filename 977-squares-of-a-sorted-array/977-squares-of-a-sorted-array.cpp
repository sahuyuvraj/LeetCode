class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        vector<int>res(nums.size(),0);
        
        while(left<=right){
            if(abs(nums[left])<=abs(nums[right]))
                res[right-left]=nums[right]*nums[right],right--;
            else
             res[right-left]=nums[left]*nums[left],left++;   
        }
        
        return res;
    }
};       