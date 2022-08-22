class Solution {
public:

    vector<vector<int>>ans;
    
    void solve(vector<int>&nums,int ind){
        if(nums.size()==ind){
            ans.push_back(nums);
            return;
        }
        
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            solve(nums,ind+1);
            swap(nums[ind],nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        ans.clear();
    
        solve(nums,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};