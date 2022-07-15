class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        if(n==1)return {nums[0]};
        int cnt=1;
        
        if(n==2 ){
            if(nums[0]!=nums[1])
                return {nums[0],nums[1]};
            return {nums[0]};
        }

        sort(nums.begin(),nums.end());
        
        for(int i=1;i<n;i++){
         if(nums[i]==nums[i-1]){
             cnt++;
             if(cnt>n/3 ){
                 if(!ans.size())
                   ans.push_back(nums[i]);
                  else if(ans[ans.size()-1]!=nums[i])
                    ans.push_back(nums[i]);
                   cnt=1;
             }
         }else{
             cnt=1;
         }
        }
        
            return ans;
    }
};
