class Solution {
public:
    bool isValid(vector<int>&arr2,int num,int d){
        int low=0,high=arr2.size()-1,mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(abs(arr2[mid]-num)<=d)return false;
            if(arr2[mid]>num)high=mid-1;
            else low=mid+1;
        }
        return true;
    }
    
    
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int cnt=0;
        for(auto num:arr1)
            if(isValid(arr2,num,d))
                cnt++;
        return cnt;
    }
};