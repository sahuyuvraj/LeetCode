class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        unordered_set<int>s;
        for(int i:nums)s.insert(i);
        
        int curr=1,sum=1;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]-1)==s.end()){
                curr=1;
                while(s.find(nums[i]+curr)!=s.end())curr++;
                sum=max(sum,curr);
            }
        }
        return sum;
    }
};