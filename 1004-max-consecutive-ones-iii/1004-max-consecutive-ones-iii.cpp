class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0,start=0;
        int cntzero=0;
        
        for(int end=0;end<nums.size();end++){
            
            if(nums[end]==0)cntzero++;
            
            while(cntzero>k){
                if(nums[start]==0)cntzero--;
                start++;
            }
            
            ans=max(ans,end-start+1);
        }
        return ans;
    }
};