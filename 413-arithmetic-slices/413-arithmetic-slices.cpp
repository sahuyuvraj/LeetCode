class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        if(nums.size()<3)return 0;
        
        int ind=0;             //index of last ele of slice 3
        int prev_diff=nums[1]-nums[0]; //diff of first slot of slice
        int cnt=0;                     //count
        
        for(int i=1;i<nums.size()-1;i++){  //making slice of 3 consecutive elements
            int diff=nums[i+1]-nums[i];
            if(diff==prev_diff)ind++;
            else prev_diff=diff,ind=0;
            cnt+=ind;
        }
        
        return cnt;
    }
};