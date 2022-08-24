class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>ans(l.size(),true);
        
        for(int i=0;i<l.size();i++){
            
            vector<int>curr;
            
            for(int j=l[i];j<=r[i];j++) curr.push_back(nums[j]);
            
            sort(curr.begin(),curr.end());
            int diff=0;
            if(curr.size()>1)diff=curr[1]-curr[0];
            for(int j=1;j<curr.size();j++){
                if(curr[j]-curr[j-1]!=diff){ans[i]=false;break;}
            }
        }
        return ans;
    }
};