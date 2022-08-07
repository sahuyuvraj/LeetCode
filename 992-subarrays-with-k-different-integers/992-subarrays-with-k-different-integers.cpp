class Solution {
public:
    
    int atMost(vector<int>&nums,int k){
        int n=nums.size();
        int cnt=0;
        unordered_map<int,int>mp;
        
        int left=0;
        for(int right=0;right<n;right++){
            
            mp[nums[right]]++;
            if(mp.size()>k){
                
                while(mp.size()>k){
                    mp[nums[left]]--;
                    if(mp[nums[left]]==0)mp.erase(nums[left]);
                    left++;
                }
            }
            
            cnt+=right-left+1;
        }
        return cnt;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
     
        return atMost(nums,k)-atMost(nums,k-1);
        
    }
};