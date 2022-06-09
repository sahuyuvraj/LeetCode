class Solution {
public:
    int specialArray(vector<int>& nums) {
        int mp[1001]={0};
        for(int num:nums)mp[num]++;
        int total=nums.size();
        for(int i=0;i<1001;i++){
            if(i==total)return i;
            total-=mp[i];
        }
        return -1;
    }
};