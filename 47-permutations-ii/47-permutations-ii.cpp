class Solution {
public:
    map<vector<int>,int>mp;
    vector<vector<int>>ans;
    
    void solve(vector<int>&nums,int ind){
        if(ind==nums.size()){
            if(!mp[nums]){
                ans.push_back(nums);
                mp[nums]++;
            }
            return;
        }
        
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            solve(nums,ind+1);
            swap(nums[ind],nums[i]);
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ans.clear();
        mp.clear();
        solve(nums,0);
        return ans;
    }
};