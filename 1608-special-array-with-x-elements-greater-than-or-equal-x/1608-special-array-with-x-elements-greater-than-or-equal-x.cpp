class Solution {
public:
    int count(vector<int>&nums,int mid){
        int cnt=0;
        for(int num:nums)if(num>=mid)cnt++;
        return cnt;
    }
    int specialArray(vector<int>& nums) {
    
        int low=0,high=*max_element(nums.begin(),nums.end()),mid;
        while(low<=high){
            mid=low+(high-low)/2;
            int cnt=count(nums,mid);
            if(cnt==mid)return mid;
            if(cnt>mid)low=mid+1;
            else high=mid-1;
        }
        return -1;
        
    //     int mp[1001]={0};
    //     for(int num:nums)mp[num]++;
    //     int total=nums.size();
    //     for(int i=0;i<1001;i++){
    //         if(i==total)return i;
    //         total-=mp[i];
    //     }
    //     return -1;
     }
};